/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hyperboloid_primitive.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 21:29:58 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/18 09:28:40 by stanaka2         ###   ########.fr       */
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

/*
    scale  = (center_radius, center_radius, c)
    z_scale = half_height * center_radius / sqrt(cap^2 - center^2)
    z_max  = half_height / c = sqrt((cap / center)^2 - 1)
*/
bool	set_hyperboloid_primitive(\
	t_object_id id, t_hyperboloid const *hyperboloid)
{
	t_primitive_frame	frame;
	t_primitive			prim;
	float				radius_diff;
	float				z_scale;

	frame.type = UNIT_HYPERBOLOID;
	frame.basis = mat3_build_onb(hyperboloid->dir);
	frame.origin = hyperboloid->center;
	radius_diff = hyperboloid->cap_radius * hyperboloid->cap_radius \
					- hyperboloid->center_radius * hyperboloid->center_radius;
	z_scale = hyperboloid->half_height * hyperboloid->center_radius \
				/ sqrtf(radius_diff);
	frame.scale = vec3(\
			hyperboloid->center_radius, hyperboloid->center_radius, z_scale);
	frame.z_range.max = hyperboloid->half_height / z_scale;
	frame.z_range.min = -frame.z_range.max;
	if (!build_primitive(&frame, &prim))
		return (false);
	set_primitive(id, &prim);
	return (true);
}
