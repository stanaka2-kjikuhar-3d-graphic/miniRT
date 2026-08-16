/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_primitive_tbn.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 20:33:12 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/08/16 20:52:39 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "config.h"
#include "matrix.h"
#include "object.h"
#include "vector.h"

#include "../object_private.h"

static t_vec3	local_tangent(t_primitive const *prim, t_vec3 normal);
static t_vec3	local_bitangent(\
					t_primitive const *prim, t_vec3 point, \
					enum e_uv_type uv_type);
static t_vec3	to_world_dir(t_primitive const *prim, t_vec3 v);
static bool		v_grows_with_z(enum e_primitive_type type);

/* Tangent frame T, B, N in the columns. See docs/primitive_tbn.md. */
t_mat3	calc_primitive_tbn(t_primitive const *prim, t_vec3 point, \
			t_vec3 normal, enum e_uv_type uv_type)
{
	t_vec3	v;

	if (prim->type == UNIT_CYLINDER || prim->type == UNIT_DISC)
	{
		v = to_world_dir(prim, local_bitangent(prim, point, uv_type));
		return (mat3_from_columns(vec3_cross(normal, v), v, normal));
	}
	v = to_world_dir(prim, local_tangent(prim, normal));
	if (v_grows_with_z(prim->type))
		return (mat3_from_columns(v, vec3_cross(normal, v), normal));
	return (mat3_from_columns(v, vec3_cross(v, normal), normal));
}

static t_vec3	local_tangent(t_primitive const *prim, t_vec3 normal)
{
	t_mat3	basis;
	t_vec3	local;

	if (prim->type == UNIT_PLANE)
		return (vec3(1.0f, 0.0f, 0.0f));
	basis = mat3_from_mat4(&(prim->to_world));
	local = mat3_mul_t_vec3(&basis, normal);
	if (local.x * local.x + local.y * local.y < EPSILON * EPSILON)
		return (vec3(1.0f, 0.0f, 0.0f));
	return (vec3(-local.y, local.x, 0.0f));
}

static t_vec3	local_bitangent(\
	t_primitive const *prim, t_vec3 point, enum e_uv_type uv_type)
{
	t_vec3	local;

	if (prim->type == UNIT_CYLINDER)
		return (vec3(0.0f, 0.0f, -1.0f));
	local = mat4_transform_point(&(prim->to_local), point);
	if (uv_type == UV_LOWER_CAP)
		return (vec3(-local.x, -local.y, 0.0f));
	if (local.x * local.x + local.y * local.y < EPSILON * EPSILON)
		return (vec3(1.0f, 0.0f, 0.0f));
	return (vec3(local.x, local.y, 0.0f));
}

static t_vec3	to_world_dir(t_primitive const *prim, t_vec3 v)
{
	return (vec3_normalize(mat4_transform_dir(&(prim->to_world), v)));
}

static bool	v_grows_with_z(enum e_primitive_type type)
{
	return (type == UNIT_PLANE || type == UNIT_CONE \
		|| type == UNIT_PARABOLOID);
}
