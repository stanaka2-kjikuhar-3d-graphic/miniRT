/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 21:18:19 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/10/04 21:18:19 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "ray.h"
#include "color.h"

#include "intersection.h"
#include "phong.h"
#include "../renderer_private.h"

void	phong_pixel(t_ivec2 pixel)
{
	t_ray	ray;
	t_hit	hit;
	t_color	color;

	ray = calc_camera_ray(pixel);
	hit = find_closest_hit(&ray);
	if (hit.object == NULL)
		color = (t_color){.r = 0.0f, .g = 0.0f, .b = 0.0f};
	else
		color = phong_lighting(&ray, &hit);
	put_color_to_window_image(pixel, color);
}
