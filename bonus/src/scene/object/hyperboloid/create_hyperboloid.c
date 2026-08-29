/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_hyperboloid.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 19:47:07 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/29 16:23:14 by stanaka2         ###   ########.fr       */
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
					t_input_hyperboloid const *in, t_vec3 dir, \
					enum e_uv_type type);
static void		set_hyperboloid_uv(\
					t_object *object, t_input_hyperboloid const *input);
static bool		set_hyperboloid_primitive(t_object *object, \
					t_input_hyperboloid const *input, t_vec3 dir);
static t_aabb	calc_hyperboloid_aabb(\
					t_input_hyperboloid const *input, t_vec3 dir);

bool	create_hyperboloid(t_input_hyperboloid const *input)
{
	t_object	object;
	t_vec3		dir;

	dir = vec3_normalize(input->dir);
	set_material_from_option(&(object.material), input->albedo, \
		&(input->option.material));
	set_hyperboloid_uv(&object, input);
	if (!set_hyperboloid_primitive(&object, input, dir))
		return (false);
	object.aabb = calc_hyperboloid_aabb(input, dir);
	object.aabb_centroid = calc_aabb_centroid(&(object.aabb));
	object.has_bounded_aabb = has_bounded_aabb(&(object.aabb));
	if (!create_object(&object))
		return (false);
	return (add_cap_circle(&object, input, dir, UV_UPPER_CAP) \
				&& add_cap_circle(&object, input, dir, UV_LOWER_CAP));
}

static void	set_hyperboloid_uv(\
	t_object *object, t_input_hyperboloid const *input)
{
	float	cap_ratio;

	object->uv.type = UV_DEFAULT;
	set_uv_checker(&(object->uv), input->option.checker_count);
	object->uv.u_per_v = (float)(2.0f * M_PI * input->cap_radius) \
							/ (2.0f * (input->cap_radius + input->half_height));
	object->uv.u_range = (t_range){.min = 0.0f, .max = 1.0f};
	cap_ratio = input->cap_radius \
					/ (2.0f * (input->cap_radius + input->half_height));
	object->uv.v_range = (t_range){.min = cap_ratio, .max = 1.0f - cap_ratio};
}

static bool	add_cap_circle(t_object const *object, \
	t_input_hyperboloid const *src, t_vec3 dir, enum e_uv_type uv_type)
{
	t_input_circle	input;

	input.albedo = object->material.albedo;
	if (uv_type == UV_UPPER_CAP)
		input.normal = dir;
	else
		input.normal = vec3_scale(-1.0f, dir);
	input.center = vec3_add(src->center, \
					vec3_scale(src->half_height, input.normal));
	input.radius = src->cap_radius;
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

/*
    scale  = (center_radius, center_radius, c)
    c      = half_height * center_radius / sqrt(cap^2 - center^2)
    z_max  = half_height / c = sqrt((cap / center)^2 - 1)
*/
static bool	set_hyperboloid_primitive(\
	t_object *object, t_input_hyperboloid const *input, t_vec3 dir)
{
	t_primitive_frame	frame;
	float				radius_diff;
	float				c;

	radius_diff = input->cap_radius * input->cap_radius \
					- input->center_radius * input->center_radius;
	c = input->half_height * input->center_radius / sqrtf(radius_diff);
	frame.type = UNIT_HYPERBOLOID;
	frame.basis = calc_onb(dir);
	frame.origin = input->center;
	frame.scale = vec3(input->center_radius, input->center_radius, c);
	frame.z_range.max = input->half_height / c;
	frame.z_range.min = -frame.z_range.max;
	return (build_primitive(&frame, &(object->primitive)));
}

static t_aabb	calc_hyperboloid_aabb(\
	t_input_hyperboloid const *input, t_vec3 dir)
{
	t_vec3	circle_extent;
	t_vec3	top;
	t_vec3	bottom;

	circle_extent = vec3(\
		input->cap_radius * sqrtf(1.0f - dir.x * dir.x), \
		input->cap_radius * sqrtf(1.0f - dir.y * dir.y), \
		input->cap_radius * sqrtf(1.0f - dir.z * dir.z) \
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
