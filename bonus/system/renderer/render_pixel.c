/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 21:06:09 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/11/03 19:23:51 by stanaka2         ###   ########.fr       */
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

void	render_pixel(t_ivec2 pixel, uint32_t *seed)
{
	t_color	color;

	if (get_render_mode() == RENDER_MODE_PHONG)
		color = phong_pixel(pixel, seed);
	else
		color = raytrace(pixel, seed);
	put_color_viewport(get_buffering_mode(), pixel, color);
}
