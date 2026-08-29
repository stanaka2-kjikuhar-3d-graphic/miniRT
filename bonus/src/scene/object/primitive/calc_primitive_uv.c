/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_primitive_uv.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 19:25:41 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/08/29 21:38:59 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "matrix.h"
#include "object.h"
#include "vector.h"

#include "../object_private.h"

static t_vec2	lateral_uv(t_primitive const *prim, t_vec3 p);
static t_vec2	plane_uv(t_vec3 p, t_vec2 pattern_scale);
static t_vec2	disc_uv(t_vec3 p, enum e_uv_type uv_type);

/* UV from the canonical local point. See docs/primitive_uv.md. */
t_vec2	calc_primitive_uv(\
	t_primitive const *prim, t_vec3 point, t_uv const *uv)
{
	t_vec3	local;

	local = mat4_transform_point(&(prim->to_local), point);
	if (prim->type == INFINITE_PLANE || prim->type == UNIT_PLANE)
		return (plane_uv(local, uv->pattern_scale));
	else if (prim->type == UNIT_DISC)
		return (disc_uv(local, uv->type));
	else
		return (lateral_uv(prim, local));
}

static t_vec2	plane_uv(t_vec3 p, t_vec2 pattern_scale)
{
	t_vec2	uv;

	uv.u = (p.x * pattern_scale.u) - 0.5f;
	uv.v = (p.y * pattern_scale.v) - 0.5f;
	uv.u -= floorf(uv.u);
	uv.v -= floorf(uv.v);
	return (uv);
}

static t_vec2	disc_uv(t_vec3 p, enum e_uv_type uv_type)
{
	t_vec2	uv;

	uv.u = (float)((atan2f(p.y, p.x) + M_PI) / (2.0f * M_PI));
	uv.v = sqrtf(p.x * p.x + p.y * p.y);
	if (uv_type == UV_LOWER_CAP)
	{
		uv.u = 1.0f - uv.u;
		uv.v = 1.0f - uv.v;
	}
	return (uv);
}

static t_vec2	lateral_uv(t_primitive const *prim, t_vec3 p)
{
	t_vec2	uv;

	uv.u = (float)((atan2f(p.y, p.x) + M_PI) / (2.0f * M_PI));
	if (prim->type == UNIT_SPHERE)
		uv.v = 1.0f - (float)((asinf(fminf(1.0f, fmaxf(-1.0f, p.z))) \
					+ M_PI_2) / M_PI);
	else if (prim->type == UNIT_CYLINDER)
		uv.v = 0.5f - p.z / 2.0f;
	else if (prim->type == UNIT_HYPERBOLOID)
		uv.v = 0.5f - p.z / (2.0f * prim->z_range.max);
	else
		uv.v = p.z;
	return (uv);
}
