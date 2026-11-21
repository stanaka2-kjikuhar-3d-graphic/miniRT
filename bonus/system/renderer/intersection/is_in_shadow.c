/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_shadow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 14:38:36 by stanaka2          #+#    #+#             */
/*   Updated: 2026/11/06 06:57:04 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>

#include "vector.h"
#include "ray.h"
#include "range.h"
#include "config.h"

#include "./intersection_private.h"
#include "../renderer_private.h"

#define NORMAL_BIAS 0.0001f // 1e-4
#define LIGHT_BIAS 0.000001f // 1e-6

bool	is_in_shadow(t_hit const *hit, t_vec3 light_dir, float light_dist)
{
	float	scale;
	t_ray	shadow_ray;
	t_range	range;

	if (vec3_dot(hit->normal, light_dir) <= EPSILON)
		return (true);
	scale = fmaxf(1.0f, fmaxf(fabsf(hit->point.x), \
				fmaxf(fabsf(hit->point.y), fabsf(hit->point.z))));
	shadow_ray.origin = vec3_add(hit->point, \
							vec3_scale(scale * NORMAL_BIAS, hit->normal));
	shadow_ray.dir = light_dir;
	range = (t_range){.min = scale * LIGHT_BIAS, \
				.max = light_dist - scale * LIGHT_BIAS};
	return (flat_list_shading(&shadow_ray, range) \
		|| bvh_shading(&shadow_ray, range));
}
