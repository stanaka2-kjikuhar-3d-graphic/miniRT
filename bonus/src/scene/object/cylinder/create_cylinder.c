/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 15:48:27 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/13 13:50:31 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>

#include "vector.h"
#include "object.h"

#include "../object_private.h"

static bool	add_cap_circle(t_object const *object, enum e_uv_type uv_type);

bool	create_cylinder(t_input_cylinder const *input)
{
	t_object	object;
	float		cap_ratio;

	object.type = OBJ_CYLINDER;
	object.cylinder.center = input->center;
	object.cylinder.dir = vec3_normalize(input->dir);
	object.cylinder.radius = input->radius;
	object.cylinder.half_height = input->half_height;
	object.material.albedo = input->albedo;
	object.material.pattern_type = input->option.pattern_type;
	object.material.texture = input->option.texture;
	object.material.checker.color1 = input->option.checker_color1;
	object.material.checker.color2 = input->option.checker_color2;
	object.material.bump_map = input->option.bump_map;
	object.material.normal_map = input->option.normal_map;
	object.material.metalness = input->option.metalness;
	object.material.shininess = input->option.shininess;
	object.uv.type = UV_CYLINDER;
	object.uv.u_per_v = (float)(2.0f * M_PI * input->radius) \
								/ (2.0f * (input->radius + input->half_height));
	object.uv.u_range = (t_range){.max = 1.0f, .min = 0.0f};
	cap_ratio = input->radius / (2.0f * (input->radius + input->half_height));
	object.uv.v_range = (t_range){.max = 1.0f - cap_ratio, .min = cap_ratio};
	object.cylinder.onb.w = object.cylinder.dir;
	compute_onb(object.cylinder.onb.w, \
		&(object.cylinder.onb.u), &(object.cylinder.onb.v));
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
	input.option.pattern_type = object->material.pattern_type;
	input.option.texture = object->material.texture;
	input.option.checker_color1 = object->material.checker.color1;
	input.option.checker_color2 = object->material.checker.color2;
	input.option.bump_map = object->material.bump_map;
	input.option.normal_map = object->material.normal_map;
	input.option.metalness = object->material.metalness;
	input.option.shininess = object->material.shininess;
	input.option.uv_type = uv_type;
	input.option.pattern_size = input.radius * 2.0f;
	input.option.u_per_v = object->uv.u_per_v;
	input.option.u_range = (t_range){.max = 1.0f, .min = 0.0f};
	if (uv_type == UV_UPPER_CAP)
		input.option.v_range = (t_range){.max = 1.0f, .min = object->uv.v_range.max};
	else
		input.option.v_range = (t_range){.max = object->uv.v_range.min, .min = 0.0f};
	return (create_circle(&input));
}
