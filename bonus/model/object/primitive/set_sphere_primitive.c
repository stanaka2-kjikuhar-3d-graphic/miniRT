/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sphere_primitive.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 21:07:55 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/18 09:18:44 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "vector.h"
#include "primitive.h"
#include "object.h"
#include "range.h"
#include "id.h"

#include "./object_primitive_private.h"

bool	set_sphere_primitive(t_object_id id, t_sphere const *sphere)
{
	t_primitive_frame	frame;
	t_primitive			prim;

	frame.type = UNIT_SPHERE;
	frame.basis = mat3_build_onb(vec3(0.0f, 0.0f, 1.0f));
	frame.origin = sphere->center;
	frame.scale = vec3(sphere->radius, sphere->radius, sphere->radius);
	frame.z_range = (t_range){.min = -1.0f, .max = 1.0f};
	if (!build_primitive(&frame, &prim))
		return (false);
	set_primitive(id, &prim);
	return (true);
}
