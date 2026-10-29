/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_image_uv_pixel.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 18:16:53 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/18 02:18:45 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

#include "../image_private.h"

t_ivec2	calc_image_uv_pixel(t_image const *image, t_vec2 uv)
{
	t_ivec2	pixel;

	if (uv.u < 0.0f)
		pixel.x = 0;
	else if (1.0f <= uv.u)
		pixel.x = image->width - 1;
	else
		pixel.x = (int)((float)image->width * uv.u);
	if (uv.v < 0.0f)
		pixel.y = 0;
	else if (1.0f <= uv.v)
		pixel.y = image->height - 1;
	else
		pixel.y = (int)((float)image->height * uv.v);
	return (pixel);
}
