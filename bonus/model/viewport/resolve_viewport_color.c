/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_viewport_color.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 20:03:03 by stanaka2          #+#    #+#             */
/*   Updated: 2026/11/07 18:19:20 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <math.h>

#include "viewport.h"
#include "color.h"
#include "vector.h"
#include "config.h"

static t_color	bilinear_interpolation(t_vec2 uv, uint8_t resolution_scale);
static t_color	get_buffer_color(int x, int y, uint8_t resolution_scale);
static t_color	nearest_interpolation(t_vec2 uv, uint8_t resolution_scale);
static int		snap_uv_to_level_grid(\
					float uv, int size, uint8_t resolution_scale);

// 0.0 <= uv < 1.0
t_color	resolve_viewport_color(t_vec2 uv)
{
	t_viewport const	*viewport;
	uint8_t				resolution_scale;

	viewport = get_viewport();
	if (viewport->resolution.level < RESOLUTION_COUNT)
	{
		resolution_scale \
			= viewport->resolution.scale[viewport->resolution.level];
	}
	else
		resolution_scale = 1;
	if (viewport->resolution.interpolation == BILINEAR_INTERPOLATION \
		&& viewport->resolution.level < RESOLUTION_COUNT)
	{
		return (bilinear_interpolation(uv, resolution_scale));
	}
	else
		return (nearest_interpolation(uv, resolution_scale));
}

static t_color	bilinear_interpolation(t_vec2 uv, uint8_t resolution_scale)
{
	double	x;
	double	y;
	t_ivec2	pixel;
	double	tx;
	double	ty;

	x = ((double)WINDOW_WIDTH * uv.u - 0.5) / resolution_scale;
	y = ((double)WINDOW_HEIGHT * uv.v - 0.5) / resolution_scale;
	pixel = (t_ivec2){.x = (int)floor(x), .y = (int)floor(y)};
	tx = (x - pixel.x);
	ty = (y - pixel.y);
	return (add_color(add_color(add_color(\
		scale_color((float)((1.0 - tx) * (1.0 - ty)), \
			get_buffer_color(pixel.x, pixel.y, resolution_scale)), \
		scale_color((float)(tx * (1.0 - ty)), \
			get_buffer_color(pixel.x + 1, pixel.y, resolution_scale))), \
		scale_color((float)((1.0 - tx) * ty), \
			get_buffer_color(pixel.x, pixel.y + 1, resolution_scale))), \
		scale_color((float)(tx * ty), \
			get_buffer_color(pixel.x + 1, pixel.y + 1, resolution_scale))));
}

static t_color	get_buffer_color(int x, int y, uint8_t resolution_scale)
{
	t_viewport const	*viewport;
	size_t				i;

	viewport = get_viewport();
	if (x < 0)
		x = 0;
	else if (WINDOW_WIDTH / resolution_scale <= x)
		x = WINDOW_WIDTH / resolution_scale - 1;
	if (y < 0)
		y = 0;
	else if (WINDOW_HEIGHT / resolution_scale <= y)
		y = WINDOW_HEIGHT / resolution_scale - 1;
	i = ((size_t)y * WINDOW_WIDTH + x) * resolution_scale;
	return (viewport->buffer[i]);
}

static t_color	nearest_interpolation(t_vec2 uv, uint8_t resolution_scale)
{
	t_viewport const	*viewport;
	t_ivec2				pixel;
	size_t				i;

	viewport = get_viewport();
	pixel.x = snap_uv_to_level_grid(uv.u, WINDOW_WIDTH, resolution_scale);
	pixel.y = snap_uv_to_level_grid(uv.v, WINDOW_HEIGHT, resolution_scale);
	i = (size_t)pixel.y * WINDOW_WIDTH + pixel.x;
	return (scale_color(\
				1.0f / (float)viewport->sample_count, viewport->buffer[i]));
}

static int	snap_uv_to_level_grid(float uv, int size, uint8_t resolution_scale)
{
	double	pixel;

	pixel = (double)size * uv;
	if (resolution_scale == 1)
	{
		if (size <= pixel)
			pixel = size - 1;
		return ((int)pixel);
	}
	else
	{
		pixel += (int)(resolution_scale / 2) - 0.5;
		if (size <= pixel)
			pixel = size - 1;
		return (resolution_scale * (int)(pixel / resolution_scale));
	}
}
