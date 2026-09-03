/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_paraboloid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 19:05:58 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/16 21:37:07 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>

#include "vector.h"
#include "matrix.h"
#include "object.h"

#include "../object_private.h"

static bool	set_primitive(t_object *object, \
				t_input_paraboloid const *input, t_vec3 dir);

bool	create_paraboloid(t_input_paraboloid const *input)
{
	t_object	object;
	float		top_radius;
	t_vec3		dir;

	dir = vec3_normalize(input->dir);
	set_material_from_option(&(object.material), input->albedo, \
		&(input->option.material));
	object.uv.type = UV_DEFAULT;
	set_uv_checker(&(object.uv), input->option.checker_count);
	top_radius = sqrtf(input->quadratic_coefficient * input->height);
	object.uv.u_per_v = (float)(2.0f * M_PI * top_radius) / input->height;
	object.uv.u_range = (t_range){.max = 1.0f, .min = 0.0f};
	object.uv.v_range = (t_range){.max = 1.0f, .min = 0.0f};
	if (!set_primitive(&object, input, dir))
		return (false);
	return (create_object(&object));
}

/*
  x^2 + y^2 = a * z  ->  X^2 + Y^2 = Z  needs s^2 = a * sz.
  taking sz = height gives s = sqrt(a * height) and Z in [0, 1].
*/
static bool	set_primitive(t_object *object, \
	t_input_paraboloid const *input, t_vec3 dir)
{
	t_primitive_frame	frame;
	float				radius;

	radius = sqrtf(input->quadratic_coefficient * input->height);
	frame.type = UNIT_PARABOLOID;
	frame.basis = calc_onb(dir);
	frame.origin = input->center;
	frame.scale = vec3(radius, radius, input->height);
	frame.z_range = (t_range){.max = 1.0f, .min = 0.0f};
	return (build_primitive(&frame, &(object->primitive)));
}
