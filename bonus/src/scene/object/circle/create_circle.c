/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_circle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 05:59:00 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/14 01:26:14 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>

#include "config.h"
#include "matrix.h"
#include "object.h"
#include "vector.h"

#include "../object_private.h"

static bool		set_primitive(t_object *object, t_input_circle const *input);
static t_aabb	calc_circle_aabb(t_circle const *circle);

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
	set_onb(object.circle.normal, &(object.circle.onb));
	if (!set_primitive(&object, input))
		return (false);
	object.aabb = calc_circle_aabb(&(object.circle));
	object.aabb_centroid = calc_aabb_centroid(&(object.aabb));
	object.has_bounded_aabb = has_bounded_aabb(&(object.aabb));
	return (create_object(&object));
}

static bool	set_primitive(t_object *object, t_input_circle const *input)
{
	t_primitive_frame	frame;

	frame.type = UNIT_DISC;
	frame.basis = basis_from_dir(object->circle.normal);
	frame.origin = input->center;
	frame.scale = vec3(input->radius, input->radius, 1.0f);
	frame.z_range = (t_range){.min = 0.0f, .max = 0.0f};
	return (build_primitive(&frame, &(object->primitive)));
}

static t_aabb	calc_circle_aabb(t_circle const *circle)
{
	t_vec3	extent;

	extent = vec3(\
		circle->radius * sqrtf(1.0f - circle->normal.x * circle->normal.x), \
		circle->radius * sqrtf(1.0f - circle->normal.y * circle->normal.y), \
		circle->radius * sqrtf(1.0f - circle->normal.z * circle->normal.z) \
	);
	return (calc_aabb_from_extent(circle->center, extent));
}
