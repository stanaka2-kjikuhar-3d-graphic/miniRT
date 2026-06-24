/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 00:48:01 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/23 13:39:13 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "config.h"
#include "vector.h"
#include "object.h"
#include "ray.h"

float	intersect_plane(t_plane const *plane, t_ray const *ray)
{
	float	dot;
	t_vec3	to_camera;
	float	t;

	dot = vec3_dot(plane->normal, ray->dir);
	if (fabs(dot) < EPSILON)
		return (NAN);
	to_camera = vec3_sub(ray->origin, plane->pos);
	t = -vec3_dot(plane->normal, to_camera) / dot;
	if (t < 0)
		return (NAN);
	return (t);
}
