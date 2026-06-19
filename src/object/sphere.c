/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 19:51:41 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/19 12:48:13 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "vector.h"
#include "object.h"
#include "ray.h"

double	intersect_sphere(t_sphere const *sphere, t_ray const *ray)
{
	t_dvec3	to_center;
	double	perp_t;
	double	squared_dist;
	double	squared_r;
	double	t;

	to_center = dvec3_sub(sphere->center, ray->origin);
	perp_t = dvec3_dot(to_center, ray->dir);
	squared_dist = dvec3_dot(to_center, to_center) - (perp_t * perp_t);
	squared_r = sphere->radius * sphere->radius;
	if (squared_dist > squared_r)
		return (NAN);
	t = perp_t - sqrt(squared_r - squared_dist);
	if (t >= 0)
		return (t);
	t = perp_t + sqrt(squared_r - squared_dist);
	if (t >= 0)
		return (t);
	return (NAN);
}

t_dvec3	calc_sphere_normal(\
	t_sphere const *sphere, t_ray const *ray, t_dvec3 point)
{
	t_dvec3	normal;

	normal = dvec3_normalize(dvec3_sub(point, sphere->center));
	if (dvec3_dot(normal, ray->dir) > 0)
		return (dvec3_scale(-1, normal));
	return (normal);
}
