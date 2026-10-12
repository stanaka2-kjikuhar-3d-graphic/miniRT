/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cylinder_primitive.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 21:29:55 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/10 20:50:44 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "vector.h"
#include "primitive.h"
#include "object.h"

#include "./object_primitive_private.h"

bool	set_cylinder_primitive(size_t id, t_cylinder const *cylinder)
{
	t_primitive_frame	frame;
	t_primitive			prim;

	frame.type = UNIT_CYLINDER;
	frame.basis = mat3_build_onb(cylinder->dir);
	frame.origin = cylinder->center;
	frame.scale \
		= vec3(cylinder->radius, cylinder->radius, cylinder->half_height);
	frame.z_range = (t_range){.min = -1.0f, .max = 1.0f};
	if (!build_primitive(&frame, &prim))
		return (false);
	set_primitive(id, &prim);
	return (true);
}
