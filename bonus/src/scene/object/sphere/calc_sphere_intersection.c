/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_sphere_intersection.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 19:51:41 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/12 23:47:30 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "vector.h"
#include "object.h"
#include "ray.h"

float	calc_sphere_intersection(t_sphere const *sphere, t_ray const *ray)
{
	t_vec3	to_center;
	float	perp_t;
	float	squared_dist;
	float	squared_r;
	float	t;

	to_center = vec3_sub(sphere->center, ray->origin);
	perp_t = vec3_dot(to_center, ray->dir);
	squared_dist = vec3_dot(to_center, to_center) - (perp_t * perp_t);
	squared_r = sphere->radius * sphere->radius;
	if (squared_dist > squared_r)
		return (NAN);
	t = perp_t - sqrtf(squared_r - squared_dist);
	if (t >= 0.0f)
		return (t);
	t = perp_t + sqrtf(squared_r - squared_dist);
	if (t >= 0.0f)
		return (t);
	return (NAN);
}
