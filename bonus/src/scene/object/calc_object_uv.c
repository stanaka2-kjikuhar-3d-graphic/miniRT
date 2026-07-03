/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_object_uv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 19:39:56 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/03 19:52:45 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

#include "./object_private.h"

t_vec2	calc_object_uv(t_object const *object, t_vec3 point)
{
	if (object->type == OBJ_SPHERE)
		return ((t_vec2){.u = 0.0f, .v = 0.0f});
	else if (object->type == OBJ_PLANE)
		return (calc_plane_uv(&(object->plane), point));
	else if (object->type == OBJ_CYLINDER)
		return ((t_vec2){.u = 0.0f, .v = 0.0f});
	else if (object->type == OBJ_CIRCLE)
		return ((t_vec2){.u = 0.0f, .v = 0.0f});
	return ((t_vec2){.u = 0.0f, .v = 0.0f});
}
