/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_circle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 09:20:59 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/19 19:29:00 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "vector.h"
#include "object.h"
#include "ray.h"

double	intersect_circle(t_circle const *circle, t_ray const *ray)
{
	double	dot;
	t_dvec3	to_camera;
	double	t;
	t_dvec3	point;

	dot = dvec3_dot(circle->normal, ray->dir);
	if (fabs(dot) < 1e-8)
		return (NAN);
	to_camera = dvec3_sub(ray->origin, circle->center);
	t = -dvec3_dot(circle->normal, to_camera) / dot;
	if (t < 0)
		return (NAN);
	point = dvec3_add(ray->origin, dvec3_scale(t, ray->dir));
	if (dvec3_length(dvec3_sub(point, circle->center)) > circle->radius)
		return (NAN);
	return (t);
}
