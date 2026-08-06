/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 15:48:27 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/07 01:22:19 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>

#include "vector.h"
#include "matrix.h"
#include "object.h"

#include "../object_private.h"

static bool	add_cap_circle(t_object const *object, enum e_uv_type uv_type);
static void	set_cylinder_uv(\
				t_object *object, t_input_cylinder const *input);
static bool	set_primitive(t_object *object, t_input_cylinder const *input);

bool	create_cylinder(t_input_cylinder const *input)
{
	t_object	object;

	object.type = OBJ_CYLINDER;
	object.cylinder.center = input->center;
	object.cylinder.dir = vec3_normalize(input->dir);
	object.cylinder.radius = input->radius;
	object.cylinder.half_height = input->half_height;
	set_material_from_option(&(object.material), input->albedo, \
		&(input->option.material));
	set_cylinder_uv(&object, input);
	object.cylinder.onb.w = object.cylinder.dir;
	calc_onb(object.cylinder.onb.w, \
		&(object.cylinder.onb.u), &(object.cylinder.onb.v));
	if (!set_primitive(&object, input))
		return (false);
	if (!create_object(&object))
		return (false);
	return (add_cap_circle(&object, UV_UPPER_CAP) \
				&& add_cap_circle(&object, UV_LOWER_CAP));
}

static bool	add_cap_circle(t_object const *object, enum e_uv_type uv_type)
{
	t_input_circle	input;

	input.albedo = object->material.albedo;
	if (uv_type == UV_UPPER_CAP)
		input.normal = object->cylinder.dir;
	else
		input.normal = vec3_scale(-1.0f, object->cylinder.dir);
	input.center = vec3_add(object->cylinder.center, \
						vec3_scale(object->cylinder.half_height, input.normal));
	input.radius = object->cylinder.radius;
	set_option_from_material(&(input.option.material), &(object->material));
	input.option.uv_type = uv_type;
	input.option.pattern_size = input.radius * 2.0f;
	input.option.u_per_v = object->uv.u_per_v;
	input.option.checker_count = object->uv.checker_count;
	input.option.u_range = (t_range){.max = 1.0f, .min = 0.0f};
	if (uv_type == UV_UPPER_CAP)
		input.option.v_range = (t_range){\
			.max = object->uv.v_range.min, .min = 0.0f};
	else
		input.option.v_range = (t_range){\
			.max = 1.0f, .min = object->uv.v_range.max};
	return (create_circle(&input));
}

static bool	set_primitive(t_object *object, t_input_cylinder const *input)
{
	t_primitive_frame	frame;

	frame.type = UNIT_CYLINDER;
	frame.basis = basis_from_dir(object->cylinder.dir);
	frame.origin = input->center;
	frame.scale = vec3(input->radius, input->radius, input->half_height);
	frame.z_range = (t_range){.max = 1.0f, .min = -1.0f};
	return (build_primitive(&frame, &(object->primitive)));
}

static void	set_cylinder_uv(t_object *object, t_input_cylinder const *input)
{
	float	cap_ratio;

	object->uv.type = UV_DEFAULT;
	set_uv_checker(&(object->uv), input->option.checker_count);
	object->uv.u_per_v = (float)(2.0f * M_PI * input->radius) \
								/ (2.0f * (input->radius + input->half_height));
	object->uv.u_range = (t_range){.max = 1.0f, .min = 0.0f};
	cap_ratio = input->radius / (2.0f * (input->radius + input->half_height));
	object->uv.v_range = (t_range){.max = 1.0f - cap_ratio, .min = cap_ratio};
}
