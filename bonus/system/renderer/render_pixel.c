/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 21:06:09 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/10/31 21:24:37 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "ft_math.h"
#include "config.h"
#include "vector.h"

#include "renderer.h"
#include "./renderer_private.h"

static float	random_unit(uint32_t *seed);

void	render_pixel(t_ivec2 pixel, uint32_t *seed)
{
	t_vec2	sample;

	sample.x = (float)pixel.x + 0.5f;
	sample.y = (float)pixel.y + 0.5f;
	if (PIXEL_SAMPLE_JITTER)
	{
		sample.x = (float)pixel.x + random_unit(seed);
		sample.y = (float)pixel.y + random_unit(seed);
	}
	if (get_render_mode() == RENDER_MODE_PHONG)
		phong_pixel(pixel, sample);
	else
		raytrace(pixel, sample);
}

static float	random_unit(uint32_t *seed)
{
	return ((float)(ft_xorshift(seed) >> 8) / 16777216.0f);
}
