/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_object_tbn.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 22:51:01 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/22 00:54:44 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "vector.h"

#include "./object_private.h"

t_onb	calc_object_tbn(t_object const *object, t_vec3 point, t_vec3 normal)
{
	if (object->type == OBJ_SPHERE)
		return (calc_sphere_tbn(&(object->sphere), normal));
	else if (object->type == OBJ_PLANE)
		return (calc_plane_tbn(&(object->plane), normal));
	else if (object->type == OBJ_CYLINDER)
		return (calc_cylinder_tbn(&(object->cylinder), normal));
	else if (object->type == OBJ_CIRCLE)
		return (calc_circle_tbn(\
				&(object->circle), point, normal, object->uv.type));
	else
	{
		return ((t_onb){(t_vec3){1, 0, 0}, \
						(t_vec3){0, 1, 0}, \
						(t_vec3){0, 0, 1}});
	}
}
