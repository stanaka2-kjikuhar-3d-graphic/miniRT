/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_quadratic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 17:23:08 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/07/31 17:31:10 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "config.h"

static int	solve_linear(float b, float c, float roots[2]);
static void	sort_roots(float roots[2]);

int	solve_quadratic(float a, float b, float c, float roots[2])
{
	float	discriminant;
	float	q;

	if (fabsf(a) < EPSILON)
		return (solve_linear(b, c, roots));
	discriminant = b * b - 4.0f * a * c;
	if (discriminant < 0.0f)
		return (0);
	q = -0.5f * (b + copysignf(sqrtf(discriminant), b));
	if (fabsf(q) < EPSILON)
	{
		roots[0] = 0.0f;
		roots[1] = 0.0f;
		return (2);
	}
	roots[0] = q / a;
	roots[1] = c / q;
	sort_roots(roots);
	return (2);
}

static int	solve_linear(float b, float c, float roots[2])
{
	if (fabsf(b) < EPSILON)
		return (0);
	roots[0] = -c / b;
	return (1);
}

static void	sort_roots(float roots[2])
{
	float	tmp;

	if (roots[0] <= roots[1])
		return ;
	tmp = roots[0];
	roots[0] = roots[1];
	roots[1] = tmp;
}
