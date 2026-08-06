/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_hyperboloid.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 19:47:07 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/06 21:33:37 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>

#include "vector.h"
#include "object.h"

#include "../object_private.h"

static bool	add_cap_circle(t_object const *object, enum e_uv_type uv_type);
static void	set_hyperboloid_uv(\
				t_object *object, t_input_hyperboloid const *input);

bool	create_hyperboloid(t_input_hyperboloid const *input)
{
	t_object	object;

	object.type = OBJ_HYPERBOLOID;
	object.hyperboloid.center = input->center;
	object.hyperboloid.dir = vec3_normalize(input->dir);
	object.hyperboloid.center_radius = input->center_radius;
	object.hyperboloid.cap_radius = input->cap_radius;
	object.hyperboloid.half_height = input->half_height;
	set_material_from_option(&(object.material), input->albedo, \
		&(input->option.material));
	set_hyperboloid_uv(&object, input);
	object.hyperboloid.onb.w = object.hyperboloid.dir;
	calc_onb(object.hyperboloid.onb.w, \
		&(object.hyperboloid.onb.u), &(object.hyperboloid.onb.v));
	if (!create_object(&object))
		return (false);
	return (add_cap_circle(&object, UV_UPPER_CAP) \
				&& add_cap_circle(&object, UV_LOWER_CAP));
}

static void	set_hyperboloid_uv(\
	t_object *object, t_input_hyperboloid const *input)
{
	float	cap_ratio;

	object->uv.type = UV_DEFAULT;
	set_uv_checker(&(object->uv), input->option.checker_count);
	object->uv.u_per_v = (float)(2.0f * M_PI * input->cap_radius) \
							/ (2.0f * (input->cap_radius + input->half_height));
	object->uv.u_range = (t_range){.max = 1.0f, .min = 0.0f};
	cap_ratio = input->cap_radius \
					/ (2.0f * (input->cap_radius + input->half_height));
	object->uv.v_range = (t_range){.max = 1.0f - cap_ratio, .min = cap_ratio};
}

static bool	add_cap_circle(t_object const *object, enum e_uv_type uv_type)
{
	t_input_circle	input;

	input.albedo = object->material.albedo;
	if (uv_type == UV_UPPER_CAP)
		input.normal = object->hyperboloid.dir;
	else
		input.normal = vec3_scale(-1.0f, object->hyperboloid.dir);
	input.center = vec3_add(object->hyperboloid.center, \
					vec3_scale(object->hyperboloid.half_height, input.normal));
	input.radius = object->hyperboloid.cap_radius;
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
