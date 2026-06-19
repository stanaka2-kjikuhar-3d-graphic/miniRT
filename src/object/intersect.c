/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 00:50:10 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/19 19:24:21 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "object.h"
#include "ray.h"

#include "./object_private.h"

double	intersect(t_object const *object, t_ray const *ray)
{
	if (object->type == OBJ_SPHERE)
		return (intersect_sphere(&(object->sphere), ray));
	else if (object->type == OBJ_PLANE)
		return (intersect_plane(&(object->plane), ray));
	else if (object->type == OBJ_CYLINDER)
		return (intersect_cylinder(&(object->cylinder), ray));
	else if (object->type == OBJ_CIRCLE)
		return (intersect_circle(&(object->circle), ray));
	return (NAN);
}
