/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_aabb_intersection.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 00:58:45 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/16 21:05:05 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>

#include "aabb.h"
#include "object.h"
#include "range.h"
#include "ray.h"
#include "vector.h"

static t_range	calc_axis_range(float origin, float dir, t_range axis);

float	calc_aabb_intersection(t_aabb const *aabb, t_ray const *ray)
{
	t_range	axis_range[3];
	t_range	t;

	axis_range[X_AXIS] = calc_axis_range(ray->origin.x, ray->dir.x, aabb->x);
	axis_range[Y_AXIS] = calc_axis_range(ray->origin.y, ray->dir.y, aabb->y);
	axis_range[Z_AXIS] = calc_axis_range(ray->origin.z, ray->dir.z, aabb->z);
	t.min = fmaxf(fmaxf(fmaxf(axis_range[X_AXIS].min, axis_range[Y_AXIS].min), \
									axis_range[Z_AXIS].min), 0.0f);
	t.max = fminf(fminf(axis_range[X_AXIS].max, axis_range[Y_AXIS].max), \
							axis_range[Z_AXIS].max);
	if (t.max < t.min)
		return (NAN);
	return (t.min);
}

static t_range	calc_axis_range(float origin, float dir, t_range axis)
{
	float	t0;
	float	t1;

	if (dir == 0.0f)
	{
		if (origin < axis.min || axis.max < origin)
			return ((t_range){.min = 0.0f, .max = -INFINITY});
		return ((t_range){.min = 0.0f, .max = INFINITY});
	}
	t0 = (axis.min - origin) / dir;
	t1 = (axis.max - origin) / dir;
	return ((t_range){.min = fminf(t0, t1), .max = fmaxf(t0, t1)});
}
