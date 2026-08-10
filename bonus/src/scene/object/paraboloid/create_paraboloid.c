/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_paraboloid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 19:05:58 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/11 00:37:33 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>

#include "vector.h"
#include "matrix.h"
#include "object.h"

#include "../object_private.h"

static bool		set_primitive(\
					t_object *object, t_input_paraboloid const *input);
static t_aabb	calc_paraboloid_aabb(t_primitive const *primitive);

bool	create_paraboloid(t_input_paraboloid const *input)
{
	t_object	object;
	float		top_radius;

	object.type = OBJ_PARABOLOID;
	object.paraboloid.center = input->center;
	object.paraboloid.dir = vec3_normalize(input->dir);
	object.paraboloid.quadratic_coefficient = input->quadratic_coefficient;
	object.paraboloid.height = input->height;
	set_material_from_option(&(object.material), input->albedo, \
		&(input->option.material));
	object.uv.type = UV_DEFAULT;
	set_uv_checker(&(object.uv), input->option.checker_count);
	top_radius = sqrtf(input->quadratic_coefficient * input->height);
	object.uv.u_per_v = (float)(2.0f * M_PI * top_radius) / input->height;
	object.uv.u_range = (t_range){.min = 0.0f, .max = 1.0f};
	object.uv.v_range = (t_range){.min = 0.0f, .max = 1.0f};
	object.paraboloid.onb.w = object.paraboloid.dir;
	calc_onb(object.paraboloid.onb.w, \
		&(object.paraboloid.onb.u), &(object.paraboloid.onb.v));
	paraboloid_to_quadric(&(object.paraboloid), &(object.paraboloid.quadric));
	if (!set_primitive(&object, input))
		return (false);
	object.aabb = calc_paraboloid_aabb(&(object.primitive));
	return (create_object(&object));
}

/*
  x^2 + y^2 = a * z  ->  X^2 + Y^2 = Z  needs s^2 = a * sz.
  taking sz = height gives s = sqrt(a * height) and Z in [0, 1].
*/
static bool	set_primitive(t_object *object, t_input_paraboloid const *input)
{
	t_primitive_frame	frame;
	float				radius;

	radius = sqrtf(input->quadratic_coefficient * input->height);
	frame.type = UNIT_PARABOLOID;
	frame.basis = basis_from_dir(object->paraboloid.dir);
	frame.origin = input->center;
	frame.scale = vec3(radius, radius, input->height);
	frame.z_range = (t_range){.min = 0.0f, .max = 1.0f};
	return (build_primitive(&frame, &(object->primitive)));
}

static t_aabb	calc_paraboloid_aabb(t_primitive const *primitive)
{
	return (transform_aabb(&(primitive->to_world), \
				vec3(0.0f, 0.0f, 0.5f), vec3(1.0f, 1.0f, 0.5f)));
}
