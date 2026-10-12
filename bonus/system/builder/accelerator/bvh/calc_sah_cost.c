/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_sah_cost.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 12:37:11 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/06 15:40:33 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stddef.h>

#include "aabb.h"

static float	calc_surface_area(t_aabb const *aabb);

float	calc_sah_cost(t_aabb const *left_aabb, size_t left_count, \
	t_aabb const *right_aabb, size_t right_count)
{
	return (calc_surface_area(left_aabb) * (float)left_count \
				+ calc_surface_area(right_aabb) * (float)right_count);
}

static float	calc_surface_area(t_aabb const *aabb)
{
	float const	x = fmaxf(0.0f, aabb->x.max - aabb->x.min);
	float const	y = fmaxf(0.0f, aabb->y.max - aabb->y.min);
	float const	z = fmaxf(0.0f, aabb->z.max - aabb->z.min);

	return (2.0f * (x * y + y * z + z * x));
}
