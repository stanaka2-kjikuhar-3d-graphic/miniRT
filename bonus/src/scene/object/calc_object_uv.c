/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_object_uv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 19:39:56 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/06 02:14:07 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

#include "./object_private.h"

t_vec2	calc_object_uv(t_object const *object, t_vec3 point)
{
	t_vec2	uv;

	if (object->type == OBJ_SPHERE)
		uv = calc_sphere_uv(&(object->sphere), point);
	else if (object->type == OBJ_PLANE)
		uv = calc_plane_uv(&(object->plane), point);
	else if (object->type == OBJ_CYLINDER)
		uv = calc_cylinder_uv(&(object->cylinder), point);
	else if (object->type == OBJ_CIRCLE)
	{
		uv = calc_circle_uv(&(object->circle), point);
		if (object->material.uv_type == UV_UPPER_POLAR)
			uv.v = 1.0f - uv.v;
		else if (object->material.uv_type == UV_LOWER_POLAR)
			uv.u = 1.0f - uv.u;
	}
	else
		uv = (t_vec2){.u = 0.0f, .v = 0.0f};
	return (adjust_uv_range(\
				uv, object->material.u_range, object->material.v_range));
}
