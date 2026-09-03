/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 17:38:47 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/08/30 17:52:09 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "ray.h"
#include "color.h"

#include "./phong.h"
#include "../intersection/intersection.h"
#include "../renderer_private.h"

void	phong_pixel(t_ivec2 pixel)
{
	t_ray	ray;
	t_hit	hit;
	t_color	color;

	ray = calc_camera_ray(pixel);
	hit = find_closest_hit(&ray);
	if (hit.object != NULL)
		color = phong_lighting(&ray, &hit);
	else
		color = (t_color){.r = 0.0f, .g = 0.0f, .b = 0.0f};
	put_color_to_window_image(pixel, color);
}
