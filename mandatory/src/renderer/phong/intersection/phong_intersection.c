/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_intersection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 22:46:14 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/17 22:32:05 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "config.h"
#include "matrix.h"
#include "object.h"
#include "ray.h"

#include "../phong_private.h"

static void	set_hit_record(t_ray const *ray, t_hit *hit);

t_hit	phong_intersection(t_ray const *ray)
{
	t_hit	hit;

	hit.object = NULL;
	hit.t = INFINITY;
	infinite_objects_intersection(&hit, ray);
	bvh_intersection(&hit, ray);
	if (hit.object != NULL)
		set_hit_record(ray, &hit);
	return (hit);
}

static void	set_hit_record(t_ray const *ray, t_hit *hit)
{
	t_mat3	tbn;

	hit->point = vec3_add(ray->origin, vec3_scale(hit->t, ray->dir));
	hit->uv = calc_object_uv(hit->object, hit->point);
	hit->color = calc_object_color(hit->object, hit->uv);
	hit->normal = calc_object_normal(hit->object, ray, hit->point);
	if (hit->object->material.normal_type != NORMAL_OBJECT)
	{
		tbn = calc_object_tbn(hit->object, hit->point, hit->normal);
		if (hit->object->material.normal_type == BUMP_MAP)
			hit->normal = calc_bump_mapping(hit->object, hit->uv, &tbn);
		else if (hit->object->material.normal_type == NORMAL_MAP)
			hit->normal = calc_normal_mapping(hit->object, hit->uv, &tbn);
	}
}
