/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_object_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 02:28:56 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/03 19:41:12 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "color.h"

#include "./object_private.h"

t_color	calc_object_color(t_object const *object, t_vec2 uv)
{
	if (object->type == OBJ_SPHERE)
		return (object->sphere.material.albedo);
	else if (object->type == OBJ_PLANE)
		return (calc_plane_color(&(object->plane), uv));
	else if (object->type == OBJ_CYLINDER)
		return (object->cylinder.material.albedo);
	else if (object->type == OBJ_CIRCLE)
		return (object->circle.material.albedo);
	return ((t_color){0, 0, 0});
}
