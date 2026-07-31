/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_quadratic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 17:23:08 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/07/31 17:23:47 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "config.h"

static int	solve_linear(float b, float c, float roots[2]);

/* a*x^2 + b*x + c = 0. a=~0 falls back to the linear case. */
int	solve_quadratic(float a, float b, float c, float roots[2])
{
	float	discriminant;
	float	sqrt_discriminant;

	if (fabsf(a) < EPSILON)
		return (solve_linear(b, c, roots));
	discriminant = b * b - 4.0f * a * c;
	if (discriminant < 0.0f)
		return (0);
	sqrt_discriminant = sqrtf(discriminant);
	roots[0] = (-b - sqrt_discriminant) / (2.0f * a);
	roots[1] = (-b + sqrt_discriminant) / (2.0f * a);
	return (2);
}

static int	solve_linear(float b, float c, float roots[2])
{
	if (fabsf(b) < EPSILON)
		return (0);
	roots[0] = -c / b;
	return (1);
}
