/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 15:48:27 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/05 22:57:54 by stanaka2         ###   ########.fr       */
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
					t_input_cylinder const *input, t_vec3 dir);
static bool		set_cylinder_primitive(t_object *object, \
					t_input_cylinder const *input, t_vec3 dir);
static t_aabb	calc_cylinder_aabb(\
					t_input_cylinder const *input, t_vec3 dir);

bool	create_cylinder(t_input_cylinder const *input)
{
	t_object	object;
	t_vec3		dir;

	object.albedo = input->albedo;
	dir = vec3_normalize(input->dir);
	if (!set_cylinder_primitive(&object, input, dir))
		return (false);
	object.aabb = calc_cylinder_aabb(input, dir);
	object.aabb_centroid = calc_aabb_centroid(&(object.aabb));
	object.has_bounded_aabb = has_bounded_aabb(&(object.aabb));
	if (!create_object(&object))
		return (false);
	return (add_cap_circle(&object, input, dir) \
				&& add_cap_circle(&object, input, vec3_scale(-1.0f, dir)));
}

static bool	add_cap_circle(t_object const *object, \
	t_input_cylinder const *src, t_vec3 dir)
{
	t_input_circle	input;

	input.albedo = object->albedo;
	input.normal = dir;
	input.center = vec3_add(src->center, \
						vec3_scale(src->half_height, input.normal));
	input.radius = src->radius;
	return (create_circle(&input));
}

static bool	set_cylinder_primitive(\
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
