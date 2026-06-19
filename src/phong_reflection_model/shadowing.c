/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadowing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 14:38:36 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/19 16:01:38 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>

#include "object.h"
#include "scene.h"
#include "ray.h"
#include "./phong_reflection_model_private.h"

static bool	shadow_intersection(t_ray const *shadow_ray, t_light const *light);

bool	shadowing(t_hit const *hit, t_light const *light)
{
	t_ray	shadow_ray;
	double	offset;

	offset = 1e-8 * fmax(1.0, dvec3_length(hit->point));
	shadow_ray.origin = dvec3_add(hit->point, dvec3_scale(offset, hit->normal));
	shadow_ray.dir = dvec3_normalize(\
						dvec3_sub(light->pos, shadow_ray.origin));
	return (shadow_intersection(&shadow_ray, light));
}

static bool	shadow_intersection(t_ray const *shadow_ray, t_light const *light)
{
	t_object const *const	objects = get_objects();
	size_t const			count = get_objects_count();
	double					light_dist;
	size_t					i;
	double					t;

	light_dist = dvec3_length(\
					dvec3_sub(light->pos, shadow_ray->origin));
	i = 0;
	while (i < count)
	{
		t = intersect(&(objects[i]), shadow_ray);
		if (t != t || t <= 0 || light_dist <= t)
		{
			++i;
			continue ;
		}
		return (true);
	}
	return (false);
}
