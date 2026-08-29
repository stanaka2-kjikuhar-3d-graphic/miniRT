/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_primitive_normal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 18:51:33 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/08/29 14:43:10 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "object.h"
#include "ray.h"
#include "vector.h"

#include "../object_private.h"

static t_vec3	local_normal(enum e_primitive_type type, t_vec3 point);

/* Unit form normal via the inverse transpose. See docs/primitive_normal.md. */
t_vec3	calc_primitive_normal(\
	t_primitive const *prim, t_ray const *ray, t_vec3 point)
{
	t_mat3	inv;
	t_vec3	local;
	t_vec3	normal;

	local = mat4_transform_point(&(prim->to_local), point);
	inv = mat3_from_mat4(&(prim->to_local));
	normal = vec3_normalize(\
			mat3_mul_t_vec3(&inv, local_normal(prim->type, local)));
	if (vec3_dot(normal, ray->dir) > 0.0f)
		return (vec3_scale(-1.0f, normal));
	return (normal);
}

static t_vec3	local_normal(enum e_primitive_type type, t_vec3 point)
{
	t_mat4	q;
	t_vec4	gradient;

	if (is_planar_primitive(type))
		return (vec3(0.0f, 0.0f, 1.0f));
	else
	{
		q = unit_quadric(type);
		gradient = mat4_mul_vec4(&q, vec4_from_point(point));
		return (vec3(gradient.x, gradient.y, gradient.z));
	}
}
