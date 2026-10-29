/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hit_record.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 16:31:30 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/25 22:09:41 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "ray.h"
#include "matrix.h"
#include "vector.h"
#include "material.h"

#include "./surface_private.h"
#include "../renderer_private.h"

static t_vec3	calc_hit_normal(t_ray const *ray, t_hit *hit);

void	set_hit_record(t_ray const *ray, t_hit *hit)
{
	hit->material = get_material(hit->object->material_id);
	hit->point = vec3_add(ray->origin, vec3_scale(hit->t, ray->dir));
	hit->uv = calc_object_uv(hit->object, hit->point);
	hit->color = calc_object_color(hit->object, hit->material, hit->uv);
	hit->normal = calc_hit_normal(ray, hit);
	hit->is_front_face = true;
	if (vec3_dot(hit->normal, ray->dir) > 0.0f)
	{
		hit->is_front_face = false;
		hit->normal = vec3_scale(-1.0f, hit->normal);
	}
}

static t_vec3	calc_hit_normal(t_ray const *ray, t_hit *hit)
{
	t_vec3	normal;
	t_mat3	tbn;

	normal = calc_object_normal(hit->object, ray, hit->point);
	if (hit->material->normal_type != NORMAL_OBJECT)
	{
		tbn = calc_object_tbn(hit->object, hit->point, normal);
		if (hit->material->normal_type == BUMP_MAP)
		{
			normal = calc_bump_mapping(\
						hit->object, hit->material, hit->uv, &tbn);
		}
		else if (hit->material->normal_type == NORMAL_MAP)
			normal = calc_normal_mapping(hit->material, hit->uv, &tbn);
	}
	return (normal);
}
