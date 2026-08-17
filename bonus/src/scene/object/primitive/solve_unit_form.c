/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_unit_form.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 16:42:19 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/08/16 16:52:44 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>

#include "matrix.h"
#include "object.h"
#include "ray.h"
#include "vector.h"

#include "../object_private.h"

static t_quadric_coeffs	local_coefficients(\
							t_mat4 const *q, t_ray const *local);
static bool				local_in_bounds(\
							t_primitive const *prim, t_ray const *local, \
							float t);
static float			select_local_t(t_primitive const *prim, \
							t_ray const *local, float const roots[2], int n);

/* Solves the unit form. The local dir is unit length, so this returns s. */
float	solve_unit_form(t_primitive const *prim, t_ray const *local)
{
	t_mat4				q;
	t_quadric_coeffs	coef;
	float				roots[2];
	int					n;

	q = unit_quadric(prim->type);
	coef = local_coefficients(&q, local);
	n = solve_quadratic(coef.a, coef.b, coef.c, roots);
	return (select_local_t(prim, local, roots, n));
}

static t_quadric_coeffs	local_coefficients(\
	t_mat4 const *q, t_ray const *local)
{
	t_vec4				origin;
	t_vec4				dir;
	t_vec4				q_dir;
	t_quadric_coeffs	coef;

	origin = vec4_from_point(local->origin);
	dir = vec4_from_dir(local->dir);
	q_dir = mat4_mul_vec4(q, dir);
	coef.a = vec4_dot(dir, q_dir);
	coef.b = 2.0f * vec4_dot(origin, q_dir);
	coef.c = quadric_eval(q, origin);
	return (coef);
}

/* every unit form is bounded along z alone, so the cap test is one compare. */
static bool	local_in_bounds(\
	t_primitive const *prim, t_ray const *local, float t)
{
	float	z;

	z = local->origin.z + t * local->dir.z;
	return (prim->z_range.min <= z && z <= prim->z_range.max);
}

static float	select_local_t(t_primitive const *prim, \
	t_ray const *local, float const roots[2], int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (roots[i] >= 0.0f && local_in_bounds(prim, local, roots[i]))
			return (roots[i]);
		i++;
	}
	return (NAN);
}
