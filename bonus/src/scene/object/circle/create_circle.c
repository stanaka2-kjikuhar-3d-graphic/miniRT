/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_circle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 05:59:00 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/07 01:22:26 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "matrix.h"
#include "object.h"
#include "vector.h"

#include "../object_private.h"

static bool	set_primitive(t_object *object, t_input_circle const *input);

bool	create_circle(t_input_circle const *input)
{
	t_object	object;

	object.type = OBJ_CIRCLE;
	object.circle.center = input->center;
	object.circle.normal = vec3_normalize(input->normal);
	object.circle.radius = input->radius;
	set_material_from_option(&(object.material), input->albedo, \
		&(input->option.material));
	object.uv.type = input->option.uv_type;
	object.uv.pattern_size = input->option.pattern_size;
	set_uv_checker(&(object.uv), input->option.checker_count);
	object.uv.u_per_v = input->option.u_per_v;
	object.uv.u_range = input->option.u_range;
	object.uv.v_range = input->option.v_range;
	object.circle.onb.w = object.circle.normal;
	calc_onb(object.circle.onb.w, \
		&(object.circle.onb.u), &(object.circle.onb.v));
	if (!set_primitive(&object, input))
		return (false);
	return (create_object(&object));
}

static bool	set_primitive(t_object *object, t_input_circle const *input)
{
	t_primitive_frame	frame;

	frame.type = UNIT_DISC;
	frame.basis = basis_from_dir(object->circle.normal);
	frame.origin = input->center;
	frame.scale = vec3(input->radius, input->radius, 1.0f);
	frame.z_range = (t_range){.max = 0.0f, .min = 0.0f};
	return (build_primitive(&frame, &(object->primitive)));
}
