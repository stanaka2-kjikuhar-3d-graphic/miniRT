/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_planar_intersection.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 02:12:47 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/08/29 17:47:59 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "config.h"
#include "object.h"
#include "ray.h"
#include "vector.h"

#include "../object_private.h"

float	calc_planar_intersection(t_primitive const *prim, t_ray const *local)
{
	float	t;
	float	x;
	float	y;

	if (fabsf(local->dir.z) < EPSILON)
		return (NAN);
	t = -local->origin.z / local->dir.z;
	if (t < 0.0f)
		return (NAN);
	x = fabsf(local->origin.x + t * local->dir.x);
	y = fabsf(local->origin.y + t * local->dir.y);
	if (prim->type == INFINITE_PLANE \
		&& (prim->half_size.x < x || prim->half_size.y < y))
	{
		return (NAN);
	}
	else if (prim->type == UNIT_PLANE && (1.0f < x || 1.0f < y))
		return (NAN);
	else if (prim->type == UNIT_DISC && (1.0f < x * x + y * y))
		return (NAN);
	return (t);
}
