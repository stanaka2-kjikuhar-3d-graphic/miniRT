/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_hyperboloid.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 15:48:27 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/22 22:36:15 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>

#include "vector.h"
#include "object.h"

#include "../object_private.h"

static bool	add_cap_circle(t_object const *object, enum e_uv_type uv_type);

bool	create_hyperboloid(t_input_hyperboloid const *input)
{
	t_object	object;

	object.type = OBJ_HYPERBOLOID;
	object.hyperboloid.center = input->center;
	object.hyperboloid.dir = vec3_normalize(input->dir);
	object.hyperboloid.center_radius = input->center_radius;
	object.hyperboloid.cap_radius = input->cap_radius;
	object.hyperboloid.half_height = input->half_height;
	object.material.albedo = input->albedo;
	object.material.pattern_type = input->option.pattern_type;
	object.material.texture = input->option.texture;
	object.material.checker.color1 = input->option.checker_color1;
	object.material.checker.color2 = input->option.checker_color2;
	object.material.bump_map = input->option.bump_map;
	object.material.normal_map = input->option.normal_map;
	object.material.metalness = input->option.metalness;
	object.material.shininess = input->option.shininess;
	object.uv.type = UV_DEFAULT;
	object.uv.u_per_v = 1.0f; // TODO
	object.uv.u_range = (t_range){.max = 1.0f, .min = 0.0f}; // TODO
	object.uv.v_range = (t_range){.max = 1.0f, .min = 0.0f}; // TODO
	object.hyperboloid.onb.w = object.hyperboloid.dir;
	compute_onb(object.hyperboloid.onb.w, \
		&(object.hyperboloid.onb.u), &(object.hyperboloid.onb.v));
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
		input.normal = object->hyperboloid.dir;
	else
		input.normal = vec3_scale(-1.0f, object->hyperboloid.dir);
	input.center = vec3_add(object->hyperboloid.center, \
						vec3_scale(object->hyperboloid.half_height, input.normal));
	input.radius = object->hyperboloid.cap_radius;
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
		input.option.v_range = (t_range){.max = object->uv.v_range.min, .min = 0.0f};
	else
		input.option.v_range = (t_range){.max = 1.0f, .min = object->uv.v_range.max};
	return (create_circle(&input));
}
