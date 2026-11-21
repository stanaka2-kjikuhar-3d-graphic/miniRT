/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 21:05:45 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/11/03 19:26:25 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "vector.h"
#include "ray.h"
#include "color.h"

#include "./raytracer_private.h"
#include "../renderer_private.h"

t_color	phong_pixel(t_ivec2 pixel, uint32_t *seed)
{
	t_ray	ray;
	t_hit	hit;

	ray = calc_ray(pixel, seed);
	hit = find_closest_hit(&ray);
	if (hit.object == NULL)
		return ((t_color){.r = 0.0f, .g = 0.0f, .b = 0.0f});
	else
	{
		set_hit_record(&ray, &hit);
		return (phong_lighting(&ray, &hit));
	}
}
