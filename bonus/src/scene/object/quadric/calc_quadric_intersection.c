/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_quadric_intersection.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 17:33:18 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/07/31 17:36:19 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "vector.h"
#include "matrix.h"
#include "object.h"
#include "ray.h"

#include "../object_private.h"

static t_quadric_coeffs	quadric_coefficients(\
	t_quadric const *q, t_ray const *ray);
static float			select_quadric_t(\
	t_quadric const *q, t_ray const *ray, float const roots[2], int n);

float	calc_quadric_intersection(t_quadric const *q, t_ray const *ray)
{
	t_quadric_coeffs	coef;
	float				roots[2];
	int					n;

	coef = quadric_coefficients(q, ray);
	n = solve_quadratic(coef.a, coef.b, coef.c, roots);
	return (select_quadric_t(q, ray, roots, n));
}

static t_quadric_coeffs	quadric_coefficients(\
	t_quadric const *q, t_ray const *ray)
{
	t_vec4				origin;
	t_vec4				dir;
	t_vec4				q_dir;
	t_quadric_coeffs	coef;

	origin = vec4_from_point(ray->origin);
	dir = vec4_from_dir(ray->dir);
	q_dir = mat4_mul_vec4(q->q, dir);
	coef.a = vec4_dot(dir, q_dir);
	coef.b = 2.0f * vec4_dot(origin, q_dir);
	coef.c = quadric_eval(q->q, origin);
	return (coef);
}

static float	select_quadric_t(\
	t_quadric const *q, t_ray const *ray, float const roots[2], int n)
{
	int		i;
	t_vec3	point;

	i = 0;
	while (i < n)
	{
		if (roots[i] >= 0.0f)
		{
			point = vec3_add(ray->origin, vec3_scale(roots[i], ray->dir));
			if (quadric_in_bounds(q, point))
				return (roots[i]);
		}
		i++;
	}
	return (NAN);
}
