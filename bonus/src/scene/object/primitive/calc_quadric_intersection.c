/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_quadric_intersection.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 16:42:19 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/08/25 21:17:32 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>

#include "config.h"
#include "matrix.h"
#include "object.h"
#include "ray.h"
#include "vector.h"

#include "../object_private.h"

static t_quadric_coeffs	local_coefficients(t_mat4 const *q, t_ray const *local);
static t_roots			solve_linear(float b, float c);
static t_roots			solve_quadratic(float a, float b, float c);
static float			select_local_t(t_primitive const *prim, \
							t_ray const *local, t_roots const roots);

float	calc_quadric_intersection(t_primitive const *prim, t_ray const *local)
{
	t_mat4				q;
	t_quadric_coeffs	coeffs;

	q = unit_quadric(prim->type);
	coeffs = local_coefficients(&q, local);
	if (fabsf(coeffs.a) < EPSILON)
		return (select_local_t(prim, local, solve_linear(coeffs.b, coeffs.c)));
	return (select_local_t(prim, local, \
				solve_quadratic(coeffs.a, coeffs.b, coeffs.c)));
}

static t_quadric_coeffs	local_coefficients(t_mat4 const *q, t_ray const *local)
{
	t_vec4				origin;
	t_vec4				dir;
	t_quadric_coeffs	coef;

	origin = vec4_from_point(local->origin);
	dir = vec4_from_dir(local->dir);
	coef.a = vec4_dot(dir, mat4_mul_vec4(q, dir));
	coef.b = vec4_dot(dir, mat4_mul_vec4(q, origin)) * 2.0f;
	coef.c = vec4_dot(origin, mat4_mul_vec4(q, origin));
	return (coef);
}

static t_roots	solve_linear(float b, float c)
{
	if (fabsf(b) < EPSILON)
		return ((t_roots){.count = 0});
	return ((t_roots){.count = 1, .t = {-c / b}});
}

static t_roots	solve_quadratic(float a, float b, float c)
{
	float	discriminant;
	float	q;

	discriminant = b * b - 4.0f * a * c;
	if (discriminant < 0.0f)
		return ((t_roots){.count = 0});
	else if (discriminant < EPSILON)
		return ((t_roots){.count = 1, .t = {-b / (2.0f * a)}});
	q = -0.5f * (b + copysignf(sqrtf(discriminant), b));
	return ((t_roots){.count = 2, \
						.t = {fminf(q / a, c / q), fmaxf(q / a, c / q)}});
}

static float	select_local_t(\
	t_primitive const *prim, t_ray const *local, t_roots const roots)
{
	int		i;
	float	z;

	i = 0;
	while (i < roots.count)
	{
		if (roots.t[i] >= 0.0f)
		{
			z = local->origin.z + roots.t[i] * local->dir.z;
			if (prim->z_range.min <= z && z <= prim->z_range.max)
			{
				return (roots.t[i]);
			}
		}
		i++;
	}
	return (NAN);
}
