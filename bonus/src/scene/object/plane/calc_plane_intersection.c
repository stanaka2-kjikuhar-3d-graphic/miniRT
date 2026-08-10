/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_plane_intersection.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 00:48:01 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/11 00:13:29 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "config.h"
#include "vector.h"
#include "object.h"
#include "ray.h"

float	calc_plane_intersection(t_plane const *plane, t_ray const *ray)
{
	float	dot;
	t_vec3	to_center;
	float	t;
	t_vec3	to_point;

	dot = vec3_dot(plane->normal, ray->dir);
	if (fabsf(dot) < EPSILON)
		return (NAN);
	to_center = vec3_sub(plane->center, ray->origin);
	t = vec3_dot(plane->normal, to_center) / dot;
	if (t < 0.0f)
		return (NAN);
	if (isinf(plane->half_size.u) && isinf(plane->half_size.v))
		return (t);
	to_point = vec3_sub(vec3_add(ray->origin, vec3_scale(t, ray->dir)), \
						plane->center);
	if (fabsf(vec3_dot(to_point, plane->onb.u)) > plane->half_size.u \
		|| fabsf(vec3_dot(to_point, plane->onb.v)) > plane->half_size.v)
	{
		return (NAN);
	}
	return (t);
}
