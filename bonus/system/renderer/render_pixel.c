/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 21:06:09 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/11/03 06:09:33 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "ft_math.h"
#include "config.h"
#include "vector.h"
#include "render_mode.h"
#include "viewport.h"

#include "renderer.h"
#include "./renderer_private.h"

static float	random_unit(uint32_t *seed);

void	render_pixel(t_ivec2 pixel, uint32_t *seed)
{
	t_vec2	sample;
	t_color	color;

	sample.x = (float)pixel.x + 0.5f;
	sample.y = (float)pixel.y + 0.5f;
	if (PIXEL_SAMPLE_JITTER)
	{
		sample.x = (float)pixel.x + random_unit(seed);
		sample.y = (float)pixel.y + random_unit(seed);
	}
	if (get_render_mode() == RENDER_MODE_PHONG)
		color = phong_pixel(sample);
	else
		color = raytrace(sample);
	put_color_viewport(get_buffering_mode(), pixel, color);
}

static float	random_unit(uint32_t *seed)
{
	return ((float)(ft_xorshift(seed) >> 8) / 16777216.0f);
}
