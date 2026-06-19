/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_normal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 00:51:51 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/19 02:31:19 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "object.h"
#include "ray.h"
#include "./object_private.h"

t_dvec3	calc_normal(t_object const *object, t_ray const *ray, t_dvec3 point)
{
	if (object->type == OBJ_SPHERE)
		return (calc_sphere_normal(&(object->sphere), ray, point));
	else if (object->type == OBJ_PLANE)
		return (calc_plane_normal(&(object->plane), ray));
	else if (object->type == OBJ_CYLINDER)
		return (calc_cylinder_normal(&(object->cylinder), ray, point));
	else if (object->type == OBJ_CIRCLE)
		return (calc_circle_normal(&(object->circle), ray));
	return ((t_dvec3){0, 0, 0});
}
