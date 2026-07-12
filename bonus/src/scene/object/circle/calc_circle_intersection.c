/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_circle_intersection.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 09:20:59 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/12 23:20:48 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "config.h"
#include "vector.h"
#include "object.h"
#include "ray.h"

float	calc_circle_intersection(t_circle const *circle, t_ray const *ray)
{
	float	dot;
	t_vec3	to_camera;
	float	t;
	t_vec3	point;

	dot = vec3_dot(circle->normal, ray->dir);
	if (fabs(dot) < EPSILON)
		return (NAN);
	to_camera = vec3_sub(ray->origin, circle->center);
	t = -vec3_dot(circle->normal, to_camera) / dot;
	if (t < 0.0f)
		return (NAN);
	point = vec3_add(ray->origin, vec3_scale(t, ray->dir));
	if (vec3_length(vec3_sub(point, circle->center)) > circle->radius)
		return (NAN);
	return (t);
}
