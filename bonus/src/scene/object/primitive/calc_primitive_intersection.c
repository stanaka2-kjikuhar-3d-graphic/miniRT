/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_primitive_intersection.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 02:04:11 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/08/16 18:09:52 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "config.h"
#include "matrix.h"
#include "object.h"
#include "ray.h"
#include "vector.h"

#include "../object_private.h"

static t_ray	ray_to_local(t_mat4 const *to_local, t_ray const *ray);

/* Ray solved in the unit form space. See docs/primitive_intersection.md. */
float	calc_primitive_intersection(\
	t_primitive const *prim, t_ray const *ray)
{
	t_ray	local;
	float	len;

	local = ray_to_local(&(prim->to_local), ray);
	if (prim->type == UNIT_PLANE || prim->type == UNIT_DISC)
		return (calc_planar_intersection(prim, &local));
	len = vec3_length(local.dir);
	if (len < EPSILON)
		return (NAN);
	local.dir = vec3_div(len, local.dir);
	return (solve_unit_form(prim, &local) / len);
}

static t_ray	ray_to_local(t_mat4 const *to_local, t_ray const *ray)
{
	t_ray	local;

	local.origin = mat4_transform_point(to_local, ray->origin);
	local.dir = mat4_transform_dir(to_local, ray->dir);
	return (local);
}
