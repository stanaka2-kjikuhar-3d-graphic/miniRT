/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_shading.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 14:38:36 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/16 22:19:10 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>

#include "config.h"
#include "object.h"
#include "vector.h"
#include "ray.h"

#include "../phong_private.h"

bool	phong_shading(t_hit const *hit, t_vec3 light_dir, float light_dist)
{
	float	offset;
	t_ray	shadow_ray;
	float	dist;

	offset = SHADOW_EPSILON * fmaxf(1.0f, vec3_length(hit->point));
	shadow_ray.origin = vec3_add(hit->point, vec3_scale(offset, hit->normal));
	shadow_ray.dir = light_dir;
	dist = light_dist - EPSILON;
	return (infinite_objects_shading(&shadow_ray, dist) \
		|| bvh_shading(&shadow_ray, dist));
}
