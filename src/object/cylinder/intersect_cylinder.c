/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 02:41:38 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/19 19:26:26 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>

#include "vector.h"
#include "object.h"
#include "ray.h"

#include "../object_private.h"

static double	select_cylinder_t(\
	t_cylinder const *cylinder, t_ray const *ray, double t0, double t1);
static bool		check_cylinder_height(\
					t_cylinder const *cylinder, t_ray const *ray, double t);

double	intersect_cylinder(t_cylinder const *cylinder, t_ray const *ray)
{
	t_perp_cylinder	perp;
	t_dvec3			to_cylinder;
	double			squared_r;

	perp.ray = dvec3_sub(ray->dir, \
				dvec3_scale(dvec3_dot(ray->dir, cylinder->dir), cylinder->dir));
	perp.ray_len = dvec3_length(perp.ray);
	if (perp.ray_len < 1e-8)
		return (NAN);
	perp.ray = dvec3_scale(1 / perp.ray_len, perp.ray);
	to_cylinder = dvec3_sub(cylinder->center, ray->origin);
	perp.to_cylinder = dvec3_sub(to_cylinder, \
			dvec3_scale(dvec3_dot(to_cylinder, cylinder->dir), cylinder->dir));
	perp.nearest_t = dvec3_dot(perp.to_cylinder, perp.ray);
	perp.squared_nearest_dist = dvec3_dot(perp.to_cylinder, perp.to_cylinder) \
									- (perp.nearest_t * perp.nearest_t);
	squared_r = cylinder->radius * cylinder->radius;
	if (perp.squared_nearest_dist > squared_r)
		return (NAN);
	perp.half_chord = sqrt(squared_r - perp.squared_nearest_dist);
	return (select_cylinder_t(cylinder, ray, \
				(perp.nearest_t - perp.half_chord) / perp.ray_len, \
				(perp.nearest_t + perp.half_chord) / perp.ray_len));
}

static double	select_cylinder_t(\
	t_cylinder const *cylinder, t_ray const *ray, double t0, double t1)
{
	if (0 < t0 && check_cylinder_height(cylinder, ray, t0))
		return (t0);
	if (0 < t1 && check_cylinder_height(cylinder, ray, t1))
		return (t1);
	return (NAN);
}

static bool	check_cylinder_height(\
	t_cylinder const *cylinder, t_ray const *ray, double t)
{
	t_dvec3	point;
	double	h;

	point = dvec3_add(ray->origin, dvec3_scale(t, ray->dir));
	h = dvec3_dot(dvec3_sub(point, cylinder->center), cylinder->dir);
	if (h < -(cylinder->half_height) || cylinder->half_height < h)
		return (false);
	return (true);
}
