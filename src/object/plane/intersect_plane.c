/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 00:48:01 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/19 19:28:54 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "vector.h"
#include "object.h"
#include "ray.h"

double	intersect_plane(t_plane const *plane, t_ray const *ray)
{
	double	dot;
	t_dvec3	to_camera;
	double	t;

	dot = dvec3_dot(plane->normal, ray->dir);
	if (fabs(dot) < 1e-8)
		return (NAN);
	to_camera = dvec3_sub(ray->origin, plane->pos);
	t = -dvec3_dot(plane->normal, to_camera) / dot;
	if (t < 0)
		return (NAN);
	return (t);
}
