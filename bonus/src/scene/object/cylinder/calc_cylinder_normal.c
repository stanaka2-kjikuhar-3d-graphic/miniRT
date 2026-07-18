/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_cylinder_normal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 19:25:57 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/12 23:21:20 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "object.h"
#include "ray.h"

#include "../object_private.h"

t_vec3	calc_cylinder_normal(\
	t_cylinder const *cylinder, t_ray const *ray, t_vec3 point)
{
	t_vec3	to_point;
	float	h;
	t_vec3	normal;

	to_point = vec3_sub(point, cylinder->center);
	h = vec3_dot(to_point, cylinder->dir);
	normal = vec3_normalize(\
				vec3_sub(to_point, vec3_scale(h, cylinder->dir)));
	if (vec3_dot(normal, ray->dir) > 0.0f)
		return (vec3_scale(-1.0f, normal));
	return (normal);
}
