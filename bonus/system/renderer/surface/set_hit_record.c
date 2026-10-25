/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hit_record.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 16:31:30 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/25 17:13:00 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "object.h"
#include "ray.h"
#include "matrix.h"
#include "vector.h"

#include "./surface_private.h"
#include "../renderer_private.h"

void	set_hit_record(t_ray const *ray, t_hit *hit)
{
	t_mat3				tbn;
	t_material const	*material;

	hit->point = vec3_add(ray->origin, vec3_scale(hit->t, ray->dir));
	hit->uv = calc_object_uv(hit->object, hit->point);
	hit->color = calc_object_color(hit->object, hit->uv);
	hit->normal = calc_object_normal(hit->object, ray, hit->point);
	hit->is_front_face = true;
	if (vec3_dot(hit->normal, ray->dir) > 0.0f)
	{
		hit->is_front_face = false;
		hit->normal = vec3_scale(-1.0f, hit->normal);
	}
	material = &(hit->object->material);
	if (material->normal_type != NORMAL_OBJECT)
	{
		tbn = calc_object_tbn(hit->object, hit->point, hit->normal);
		if (material->normal_type == BUMP_MAP)
			hit->normal = calc_bump_mapping(hit->object, hit->uv, &tbn);
		else if (material->normal_type == NORMAL_MAP)
			hit->normal = calc_normal_mapping(hit->object, hit->uv, &tbn);
	}
}
