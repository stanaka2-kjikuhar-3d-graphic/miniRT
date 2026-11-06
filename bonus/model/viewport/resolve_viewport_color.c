/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_viewport_color.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 20:03:03 by stanaka2          #+#    #+#             */
/*   Updated: 2026/11/07 04:47:08 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "viewport.h"
#include "color.h"
#include "vector.h"
#include "config.h"

static t_color	nearest_interpolation(t_vec2 uv, uint8_t resolution_scale);
static int		snap_uv_to_level_grid(\
					float uv, int size, uint8_t resolution_scale);

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
	return (nearest_interpolation(uv, resolution_scale));
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

	if (uv < 0.0f)
		pixel = 0.0;
	else if (1.0f <= uv)
		pixel = size - 1;
	else
		pixel = (double)size * uv;
	if (resolution_scale == 1)
		return ((int)pixel);
	else
	{
		pixel += (int)(resolution_scale / 2) - 0.5;
		return ((int)(pixel / resolution_scale) * resolution_scale);
	}
}


