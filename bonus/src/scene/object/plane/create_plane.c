/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 15:48:24 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/17 22:32:02 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>

#include "aabb.h"
#include "matrix.h"
#include "object.h"
#include "range.h"
#include "vector.h"

#include "../object_private.h"

static bool		set_primitive(\
					t_object *object, t_input_plane const *input, \
					t_mat3 const *basis);
static t_aabb	calc_plane_aabb(\
					t_input_plane const *input, t_mat3 const *basis);

bool	create_plane(t_input_plane const *input)
{
	t_object	object;
	t_mat3		basis;

	basis = calc_onb(vec3_normalize(input->normal));
	set_material_from_option(&(object.material), input->albedo, \
		&(input->option.material));
	object.uv.type = UV_DEFAULT;
	object.uv.pattern_size = input->option.pattern_size;
	set_uv_checker(&(object.uv), input->option.checker_count);
	object.uv.u_per_v = 1.0f;
	object.uv.u_range = (t_range){.min = 0.0f, .max = 1.0f};
	object.uv.v_range = (t_range){.min = 0.0f, .max = 1.0f};
	if (!set_primitive(&object, input, &basis))
		return (false);
	object.aabb = calc_plane_aabb(input, &basis);
	object.aabb_centroid = calc_aabb_centroid(&(object.aabb));
	object.has_bounded_aabb = has_bounded_aabb(&(object.aabb));
	return (create_object(&object));
}

static bool	set_primitive(\
	t_object *object, t_input_plane const *input, t_mat3 const *basis)
{
	t_primitive_frame	frame;

	frame.type = UNIT_PLANE;
	frame.basis = *basis;
	frame.origin = input->center;
	frame.scale = vec3(input->option.half_size.u, \
			input->option.half_size.v, 1.0f);
	frame.z_range = (t_range){.min = 0.0f, .max = 0.0f};
	return (build_primitive(&frame, &(object->primitive)));
}

/*
  the u and v columns span the quad, so each world axis picks up
  half_size.u * |u[axis]| + half_size.v * |v[axis]|.

  mul_extent keeps an unbounded half_size from turning a zero
  component into NaN.
*/
static t_aabb	calc_plane_aabb(\
	t_input_plane const *input, t_mat3 const *basis)
{
	t_vec2	half_size;
	t_vec3	extent;

	half_size = input->option.half_size;
	extent = vec3(\
		mul_extent(half_size.u, fabsf(basis->m[X_AXIS][U_AXIS])) \
			+ mul_extent(half_size.v, fabsf(basis->m[X_AXIS][V_AXIS])), \
		mul_extent(half_size.u, fabsf(basis->m[Y_AXIS][U_AXIS])) \
			+ mul_extent(half_size.v, fabsf(basis->m[Y_AXIS][V_AXIS])), \
		mul_extent(half_size.u, fabsf(basis->m[Z_AXIS][U_AXIS])) \
			+ mul_extent(half_size.v, fabsf(basis->m[Z_AXIS][V_AXIS])) \
	);
	return (calc_aabb_from_extent(input->center, extent));
}
