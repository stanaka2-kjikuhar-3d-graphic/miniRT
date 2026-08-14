/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_aabb_intersection.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 00:58:45 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/11 02:27:24 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>

#include "aabb.h"
#include "object.h"
#include "range.h"
#include "ray.h"
#include "vector.h"

static t_range	calc_axis_range(float origin, float inv_dir, t_range axis);

float	calc_aabb_intersection(\
	t_vec3 ray_origin, t_vec3 ray_inv_dir, t_aabb const *aabb)
{
	t_range	axis_range[3];
	t_range	t;

	axis_range[X_AXIS] = calc_axis_range(ray_origin.x, ray_inv_dir.x, aabb->x);
	axis_range[Y_AXIS] = calc_axis_range(ray_origin.y, ray_inv_dir.y, aabb->y);
	axis_range[Z_AXIS] = calc_axis_range(ray_origin.z, ray_inv_dir.z, aabb->z);
	t.min = fmaxf(fmaxf(fmaxf(axis_range[X_AXIS].min, axis_range[Y_AXIS].min), \
									axis_range[Z_AXIS].min), 0.0f);
	t.max = fminf(fminf(axis_range[X_AXIS].max, axis_range[Y_AXIS].max), \
							axis_range[Z_AXIS].max);
	if (t.max < t.min)
		return (NAN);
	return (t.min);
}

static t_range	calc_axis_range(float origin, float inv_dir, t_range axis)
{
	float	t0;
	float	t1;

	if (isinf(inv_dir))
	{
		if (origin < axis.min || axis.max < origin)
			return ((t_range){.min = 0.0f, .max = -INFINITY});
		return ((t_range){.min = 0.0f, .max = INFINITY});
	}
	t0 = (axis.min - origin) * inv_dir;
	t1 = (axis.max - origin) * inv_dir;
	return ((t_range){.min = fminf(t0, t1), .max = fmaxf(t0, t1)});
}
