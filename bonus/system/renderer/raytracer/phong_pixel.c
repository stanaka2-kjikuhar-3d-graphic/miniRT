/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 21:05:45 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/10/31 21:21:52 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "vector.h"
#include "ray.h"
#include "color.h"

#include "./raytracer_private.h"
#include "../renderer_private.h"

void	phong_pixel(t_ivec2 pixel, t_vec2 sample)
{
	t_ray	ray;
	t_hit	hit;
	t_color	color;

	ray = calc_ray(sample);
	hit = find_closest_hit(&ray);
	if (hit.object == NULL)
		color = (t_color){.r = 0.0f, .g = 0.0f, .b = 0.0f};
	else
	{
		set_hit_record(&ray, &hit);
		color = phong_lighting(&ray, &hit);
	}
	put_color_to_window_image(pixel, color);
}
