/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_object_intersection.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 00:50:10 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/31 17:39:29 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "object.h"
#include "ray.h"

#include "./object_private.h"

float	calc_object_intersection(t_object const *object, t_ray const *ray)
{
	if (object->type == OBJ_SPHERE)
		return (calc_sphere_intersection(&(object->sphere), ray));
	else if (object->type == OBJ_PLANE)
		return (calc_plane_intersection(&(object->plane), ray));
	else if (object->type == OBJ_CYLINDER)
		return (calc_cylinder_intersection(&(object->cylinder), ray));
	else if (object->type == OBJ_CIRCLE)
		return (calc_circle_intersection(&(object->circle), ray));
	else if (object->type == OBJ_CONE)
		return (calc_cone_intersection(&(object->cone), ray));
	else if (object->type == OBJ_HYPERBOLOID)
		return (calc_hyperboloid_intersection(&(object->hyperboloid), ray));
	else if (object->type == OBJ_PARABOLOID)
		return (calc_paraboloid_intersection(&(object->paraboloid), ray));
	else if (object->type == OBJ_QUADRIC)
		return (calc_quadric_intersection(&(object->quadric), ray));
	return (NAN);
}
