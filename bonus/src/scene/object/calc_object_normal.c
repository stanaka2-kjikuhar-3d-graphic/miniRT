/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_object_normal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 00:51:51 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/31 17:39:48 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "object.h"
#include "ray.h"

#include "./object_private.h"

t_vec3	calc_object_normal(\
	t_object const *object, t_ray const *ray, t_vec3 point)
{
	if (object->type == OBJ_SPHERE)
		return (calc_sphere_normal(&(object->sphere), ray, point));
	else if (object->type == OBJ_PLANE)
		return (calc_plane_normal(&(object->plane), ray));
	else if (object->type == OBJ_CYLINDER)
		return (calc_cylinder_normal(&(object->cylinder), ray, point));
	else if (object->type == OBJ_CIRCLE)
		return (calc_circle_normal(&(object->circle), ray));
	else if (object->type == OBJ_CONE)
		return (calc_cone_normal(&(object->cone), ray, point));
	else if (object->type == OBJ_HYPERBOLOID)
		return (calc_hyperboloid_normal(&(object->hyperboloid), ray, point));
	else if (object->type == OBJ_PARABOLOID)
		return (calc_paraboloid_normal(&(object->paraboloid), ray, point));
	else if (object->type == OBJ_QUADRIC)
		return (calc_quadric_normal(&(object->quadric), ray, point));
	return ((t_vec3){.x = 0, .y = 0, .z = 0});
}
