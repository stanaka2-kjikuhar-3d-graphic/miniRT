/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_plane_primitive.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 21:30:03 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/17 01:15:46 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>
#include <math.h>

#include "vector.h"
#include "primitive.h"
#include "object.h"
#include "id.h"

#include "./object_primitive_private.h"

bool	set_plane_primitive(t_id object_id, t_plane const *plane)
{
	t_primitive_frame	frame;
	t_primitive			prim;

	if (isfinite(plane->half_size.x) \
		&& isfinite(plane->half_size.y))
	{
		frame.type = UNIT_PLANE;
		frame.scale = vec3(plane->half_size.x, plane->half_size.y, 1.0f);
	}
	else
	{
		frame.type = INFINITE_PLANE;
		frame.scale = vec3(1.0f, 1.0f, 1.0f);
		frame.half_size = plane->half_size;
	}
	frame.basis = mat3_build_onb(plane->normal);
	frame.origin = plane->center;
	if (!build_primitive(&frame, &prim))
		return (false);
	set_primitive(object_id, &prim);
	return (true);
}
