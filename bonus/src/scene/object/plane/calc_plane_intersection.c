/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_plane_intersection.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 00:48:01 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/12 23:06:15 by stanaka2         ###   ########.fr       */
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
	t_vec3	from_camera;
	float	t;

	dot = vec3_dot(plane->normal, ray->dir);
	if (fabsf(dot) < EPSILON)
		return (NAN);
	from_camera = vec3_sub(ray->origin, plane->center);
	t = -vec3_dot(plane->normal, from_camera) / dot;
	if (t >= 0.0f)
		return (t);
	return (NAN);
}
