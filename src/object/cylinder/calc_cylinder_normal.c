/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_cylinder_normal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 19:25:57 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/19 19:26:39 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "object.h"
#include "ray.h"

#include "../object_private.h"

t_dvec3	calc_cylinder_normal(\
	t_cylinder const *cylinder, t_ray const *ray, t_dvec3 point)
{
	t_dvec3	to_point;
	double	h;
	t_dvec3	normal;

	to_point = dvec3_sub(point, cylinder->center);
	h = dvec3_dot(to_point, cylinder->dir);
	normal = dvec3_normalize(\
				dvec3_sub(to_point, dvec3_scale(h, cylinder->dir)));
	if (dvec3_dot(normal, ray->dir) > 0)
		return (dvec3_scale(-1, normal));
	return (normal);
}
