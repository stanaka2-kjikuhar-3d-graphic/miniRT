/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 19:51:41 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/16 22:32:19 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>

#include "vector.h"
#include "object.h"
#include "ray.h"

double	intersect_sphere(t_sphere const *sphere, t_ray const *ray)
{
	t_dvec3	to_center;
	double	t;

	to_center = dvec3_sub(sphere->pos, ray->origin);
	t = dvec3_dot(to_center, ray->dir);
	if (t < 0 \
		|| dvec3_dot(to_center, to_center) - (t * t) \
			> sphere->radius * sphere->radius)
	{
		return (NAN);
	}
	return (t);
}
