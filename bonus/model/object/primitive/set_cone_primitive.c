/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cone_primitive.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 21:29:53 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/26 22:12:30 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "vector.h"
#include "primitive.h"
#include "object.h"
#include "range.h"

#include "./object_primitive_private.h"

/*
  the unit cone has its apex at z = 0 and opens toward +z,
  so the frame sits at the apex and its w axis looks back along -dir.
*/
bool	set_cone_primitive(t_object_id id, t_cone const *cone)
{
	t_primitive_frame	frame;
	t_primitive			prim;

	frame.type = UNIT_CONE;
	frame.basis = mat3_build_onb(cone->dir);
	frame.basis.row[X_AXIS].w *= -1;
	frame.basis.row[Y_AXIS].w *= -1;
	frame.basis.row[Z_AXIS].w *= -1;
	frame.origin = vec3_add(cone->center, vec3_scale(cone->height, cone->dir));
	frame.scale = vec3(cone->radius, cone->radius, cone->height);
	frame.z_range = (t_range){.min = 0.0f, .max = 1.0f};
	if (!build_primitive(&frame, &prim))
		return (false);
	set_primitive(id, &prim);
	return (true);
}
