/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 15:48:27 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/17 22:34:04 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>

#include "vector.h"
#include "matrix.h"
#include "object.h"
#include "range.h"
#include "aabb.h"

#include "../object_private.h"

static bool		add_cap_circle(t_object const *object, \
					t_input_cylinder const *input, t_vec3 dir, \
					enum e_uv_type type);
static void		set_cylinder_uv(\
					t_object *object, t_input_cylinder const *input);
static bool		set_primitive(\
					t_object *object, t_input_cylinder const *input, \
					t_vec3 dir);
static t_aabb	calc_cylinder_aabb(\
					t_input_cylinder const *input, t_vec3 dir);

bool	create_cylinder(t_input_cylinder const *input)
{
	t_object	object;
	t_vec3		dir;

	dir = vec3_normalize(input->dir);
	set_material_from_option(&(object.material), input->albedo, \
		&(input->option.material));
	set_cylinder_uv(&object, input);
	if (!set_primitive(&object, input, dir))
		return (false);
	object.aabb = calc_cylinder_aabb(input, dir);
	object.aabb_centroid = calc_aabb_centroid(&(object.aabb));
	object.has_bounded_aabb = has_bounded_aabb(&(object.aabb));
	if (!create_object(&object))
		return (false);
	return (add_cap_circle(&object, input, dir, UV_UPPER_CAP) \
				&& add_cap_circle(&object, input, dir, UV_LOWER_CAP));
}

static bool	add_cap_circle(t_object const *object, \
	t_input_cylinder const *src, t_vec3 dir, enum e_uv_type uv_type)
{
	t_input_circle	input;

	input.albedo = object->material.albedo;
	if (uv_type == UV_UPPER_CAP)
		input.normal = dir;
	else
		input.normal = vec3_scale(-1.0f, dir);
	input.center = vec3_add(src->center, \
						vec3_scale(src->half_height, input.normal));
	input.radius = src->radius;
	set_option_from_material(&(input.option.material), &(object->material));
	input.option.uv_type = uv_type;
	input.option.pattern_size = input.radius * 2.0f;
	input.option.u_per_v = object->uv.u_per_v;
	input.option.checker_count = object->uv.checker_count;
	input.option.u_range = (t_range){.min = 0.0f, .max = 1.0f};
	if (uv_type == UV_UPPER_CAP)
		input.option.v_range = (t_range){\
			.min = 0.0f, .max = object->uv.v_range.min};
	else
		input.option.v_range = (t_range){\
			.min = object->uv.v_range.max, .max = 1.0f};
	return (create_circle(&input));
}

static bool	set_primitive(\
	t_object *object, t_input_cylinder const *input, t_vec3 dir)
{
	t_primitive_frame	frame;

	frame.type = UNIT_CYLINDER;
	frame.basis = calc_onb(dir);
	frame.origin = input->center;
	frame.scale = vec3(input->radius, input->radius, input->half_height);
	frame.z_range = (t_range){.min = -1.0f, .max = 1.0f};
	return (build_primitive(&frame, &(object->primitive)));
}

static void	set_cylinder_uv(t_object *object, t_input_cylinder const *input)
{
	float	cap_ratio;

	object->uv.type = UV_DEFAULT;
	set_uv_checker(&(object->uv), input->option.checker_count);
	object->uv.u_per_v = (float)(2.0f * M_PI * input->radius) \
								/ (2.0f * (input->radius + input->half_height));
	object->uv.u_range = (t_range){.min = 0.0f, .max = 1.0f};
	cap_ratio = input->radius / (2.0f * (input->radius + input->half_height));
	object->uv.v_range = (t_range){.min = cap_ratio, .max = 1.0f - cap_ratio};
}

static t_aabb	calc_cylinder_aabb(t_input_cylinder const *input, t_vec3 dir)
{
	t_vec3	circle_extent;
	t_vec3	top;
	t_vec3	bottom;

	circle_extent = vec3(\
		input->radius * sqrtf(1.0f - dir.x * dir.x), \
		input->radius * sqrtf(1.0f - dir.y * dir.y), \
		input->radius * sqrtf(1.0f - dir.z * dir.z) \
	);
	top = vec3_add(input->center, \
			vec3_scale(input->half_height, dir));
	bottom = vec3_sub(input->center, \
			vec3_scale(input->half_height, dir));
	return (union_aabb(\
				calc_aabb_from_extent(top, circle_extent), \
				calc_aabb_from_extent(bottom, circle_extent) \
			));
}
