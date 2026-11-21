/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 16:15:11 by stanaka2          #+#    #+#             */
/*   Updated: 2026/11/03 19:26:39 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "ray.h"
#include "color.h"

#include "./raytracer_private.h"
#include "../renderer_private.h"

t_color	raytrace(t_ivec2 pixel, uint32_t *seed)
{
	t_ray	ray;

	ray = calc_ray(pixel, seed);
	return (trace_ray(ray, 0));
}
