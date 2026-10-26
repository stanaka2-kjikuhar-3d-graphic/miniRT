/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_paraboloid_primitive.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 21:30:01 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/26 22:12:22 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <math.h>

#include "vector.h"
#include "primitive.h"
#include "object.h"
#include "range.h"

#include "./object_primitive_private.h"

/*
  x^2 + y^2 = a * z  ->  X^2 + Y^2 = Z  needs s^2 = a * sz.
  taking sz = height gives s = sqrt(a * height) and Z in [0, 1].
*/
bool	set_paraboloid_primitive(t_object_id id, t_paraboloid const *paraboloid)
{
	t_primitive_frame	frame;
	t_primitive			prim;
	float				radius;

	frame.type = UNIT_PARABOLOID;
	frame.basis = mat3_build_onb(paraboloid->dir);
	frame.origin = paraboloid->center;
	radius = sqrtf(paraboloid->quadratic_coefficient * paraboloid->height);
	frame.scale = vec3(radius, radius, paraboloid->height);
	frame.z_range = (t_range){.min = 0.0f, .max = 1.0f};
	if (!build_primitive(&frame, &prim))
		return (false);
	set_primitive(id, &prim);
	return (true);
}
