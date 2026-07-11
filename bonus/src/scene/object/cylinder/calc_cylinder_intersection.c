/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_cylinder_intersection.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 02:41:38 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/03 22:45:26 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>

#include "config.h"
#include "vector.h"
#include "object.h"
#include "ray.h"

#include "../object_private.h"

static float	select_cylinder_t(\
	t_cylinder const *cylinder, t_ray const *ray, float t0, float t1);
static bool		check_cylinder_height(\
					t_cylinder const *cylinder, t_ray const *ray, float t);

float	calc_cylinder_intersection(t_cylinder const *cylinder, t_ray const *ray)
{
	t_perp_cylinder	perp;
	t_vec3			to_cylinder;
	float			squared_r;

	perp.ray = vec3_sub(ray->dir, \
				vec3_scale(vec3_dot(ray->dir, cylinder->dir), cylinder->dir));
	perp.ray_len = vec3_length(perp.ray);
	if (perp.ray_len < EPSILON)
		return (NAN);
	perp.ray = vec3_scale(1 / perp.ray_len, perp.ray);
	to_cylinder = vec3_sub(cylinder->center, ray->origin);
	perp.to_cylinder = vec3_sub(to_cylinder, \
			vec3_scale(vec3_dot(to_cylinder, cylinder->dir), cylinder->dir));
	perp.nearest_t = vec3_dot(perp.to_cylinder, perp.ray);
	perp.squared_nearest_dist = vec3_dot(perp.to_cylinder, perp.to_cylinder) \
									- (perp.nearest_t * perp.nearest_t);
	squared_r = cylinder->radius * cylinder->radius;
	if (perp.squared_nearest_dist > squared_r)
		return (NAN);
	perp.half_chord = sqrtf(squared_r - perp.squared_nearest_dist);
	return (select_cylinder_t(cylinder, ray, \
				(perp.nearest_t - perp.half_chord) / perp.ray_len, \
				(perp.nearest_t + perp.half_chord) / perp.ray_len));
}

static float	select_cylinder_t(\
	t_cylinder const *cylinder, t_ray const *ray, float t0, float t1)
{
	if (0 < t0 && check_cylinder_height(cylinder, ray, t0))
		return (t0);
	if (0 < t1 && check_cylinder_height(cylinder, ray, t1))
		return (t1);
	return (NAN);
}

static bool	check_cylinder_height(\
	t_cylinder const *cylinder, t_ray const *ray, float t)
{
	t_vec3	point;
	float	h;

	point = vec3_add(ray->origin, vec3_scale(t, ray->dir));
	h = vec3_dot(vec3_sub(point, cylinder->center), cylinder->dir);
	if (h < -(cylinder->half_height) || cylinder->half_height < h)
		return (false);
	return (true);
}
