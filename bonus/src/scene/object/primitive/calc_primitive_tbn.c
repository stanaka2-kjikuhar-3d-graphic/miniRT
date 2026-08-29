/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_primitive_tbn.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 20:33:12 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/08/29 22:18:51 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "config.h"
#include "matrix.h"
#include "object.h"
#include "vector.h"

#include "../object_private.h"

static t_vec3	calc_local_tangent(\
				t_primitive const *prim, t_vec3 point, enum e_uv_type uv_type);
static bool		is_left_hand_tbn_type(enum e_primitive_type type);

/* Tangent frame T, B, N in the columns. See docs/primitive_tbn.md. */
t_mat3	calc_primitive_tbn(t_primitive const *prim, t_vec3 point, \
			t_vec3 normal, enum e_uv_type uv_type)
{
	t_vec3	tangent;

	tangent = vec3_normalize(mat4_transform_dir(&(prim->to_world), \
								calc_local_tangent(prim, point, uv_type)));
	if (is_left_hand_tbn_type(prim->type))
	{
		return (mat3_from_columns(\
					tangent, vec3_cross(tangent, normal), normal));
	}
	return (mat3_from_columns(tangent, vec3_cross(normal, tangent), normal));
}

static t_vec3	calc_local_tangent(\
	t_primitive const *prim, t_vec3 point, enum e_uv_type uv_type)
{
	t_vec3	local;

	if (prim->type == INFINITE_PLANE || prim->type == UNIT_PLANE)
		return (vec3(1.0f, 0.0f, 0.0f));
	local = mat4_transform_point(&(prim->to_local), point);
	if (local.x * local.x + local.y * local.y < EPSILON * EPSILON)
		return (vec3(1.0f, 0.0f, 0.0f));
	if (uv_type == UV_LOWER_CAP)
		return (vec3(local.y, -local.x, 0.0f));
	return (vec3(-local.y, local.x, 0.0f));
}

/*
types whose T x B is -N. the reason differs between the two groups, and
both come from the v of calc_primitive_uv.c. See docs/primitive_tbn.md.

    UNIT_SPHERE / UNIT_CYLINDER / UNIT_HYPERBOLOID / UNIT_PARABOLOID
        v runs along -z, so one axis is flipped.
    UNIT_DISC
        no axis is flipped, but (u, v) = (azimuth, radius) reverses the
        right handed (r, theta, z).
*/
static bool	is_left_hand_tbn_type(enum e_primitive_type type)
{
	return (type == UNIT_SPHERE || type == UNIT_CYLINDER \
			|| type == UNIT_HYPERBOLOID || type == UNIT_PARABOLOID \
			|| type == UNIT_DISC);
}
