/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 15:48:24 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/10 20:02:45 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>

#include "matrix.h"
#include "object.h"
#include "vector.h"

#include "../object_private.h"

static bool		set_primitive(t_object *object, t_input_plane const *input);
static t_aabb	calc_plane_aabb(t_plane const *plane);

bool	create_plane(t_input_plane const *input)
{
	t_object	object;

	object.type = OBJ_PLANE;
	object.plane.center = input->center;
	object.plane.normal = vec3_normalize(input->normal);
	set_material_from_option(&(object.material), input->albedo, \
		&(input->option.material));
	object.uv.type = UV_DEFAULT;
	object.uv.pattern_size = input->option.pattern_size;
	set_uv_checker(&(object.uv), input->option.checker_count);
	object.uv.u_per_v = 1.0f;
	object.uv.u_range = (t_range){.min = 0.0f, .max = 1.0f};
	object.uv.v_range = (t_range){.min = 0.0f, .max = 1.0f};
	object.plane.half_size = input->option.half_size;
	object.plane.onb.w = object.plane.normal;
	calc_onb(object.plane.onb.w, \
		&(object.plane.onb.u), &(object.plane.onb.v));
	if (!set_primitive(&object, input))
		return (false);
	object.aabb = calc_plane_aabb(&(object.plane));
	return (create_object(&object));
}

static bool	set_primitive(t_object *object, t_input_plane const *input)
{
	t_primitive_frame	frame;

	frame.type = UNIT_PLANE;
	frame.basis = basis_from_dir(object->plane.normal);
	frame.origin = input->center;
	frame.scale = vec3(input->option.half_size.u, \
			input->option.half_size.v, 1.0f);
	frame.z_range = (t_range){.min = 0.0f, .max = 0.0f};
	return (build_primitive(&frame, &(object->primitive)));
}

static t_aabb	calc_plane_aabb(t_plane const *plane)
{
	t_vec3	extent;

	extent = vec3(\
		mul_extent(plane->half_size.u, fabsf(plane->onb.u.x)) \
			+ mul_extent(plane->half_size.v, fabsf(plane->onb.v.x)), \
		mul_extent(plane->half_size.u, fabsf(plane->onb.u.y)) \
			+ mul_extent(plane->half_size.v, fabsf(plane->onb.v.y)), \
		mul_extent(plane->half_size.u, fabsf(plane->onb.u.z)) \
			+ mul_extent(plane->half_size.v, fabsf(plane->onb.v.z)) \
	);
	return (calc_aabb_from_extent(plane->center, extent));
}
