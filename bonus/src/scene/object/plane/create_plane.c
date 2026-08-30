/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 15:48:24 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/30 19:25:57 by stanaka2         ###   ########.fr       */
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

static void		set_plane_uv(t_uv *uv, t_input_plane const *input);
static bool		set_plane_primitive(\
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
	set_plane_uv(&(object.uv), input);
	if (!set_plane_primitive(&object, input, &basis))
		return (false);
	object.aabb = calc_plane_aabb(input, &basis);
	object.aabb_centroid = calc_aabb_centroid(&(object.aabb));
	object.has_bounded_aabb = has_bounded_aabb(&(object.aabb));
	return (create_object(&object));
}

static void	set_plane_uv(t_uv *uv, t_input_plane const *input)
{
	uv->type = UV_DEFAULT;
	uv->pattern_size = input->option.pattern_size;
	set_uv_checker(uv, input->option.checker_count);
	uv->u_per_v = 1.0f;
	if (isfinite(input->option.half_size.x) \
		&& isfinite(input->option.half_size.y))
	{
		uv->pattern_scale.u \
			= input->option.half_size.x / input->option.pattern_size;
		uv->pattern_scale.v \
			= input->option.half_size.y / input->option.pattern_size;
	}
	else
	{
		uv->pattern_scale.u = 1.0f / input->option.pattern_size;
		uv->pattern_scale.v = 1.0f / input->option.pattern_size;
	}
	uv->u_range = (t_range){.min = 0.0f, .max = 1.0f};
	uv->v_range = (t_range){.min = 0.0f, .max = 1.0f};
}

static bool	set_plane_primitive(\
	t_object *object, t_input_plane const *input, t_mat3 const *basis)
{
	t_primitive_frame	frame;

	if (isfinite(input->option.half_size.x) \
		&& isfinite(input->option.half_size.y))
	{
		frame.type = UNIT_PLANE;
		frame.scale = vec3(input->option.half_size.x, \
			input->option.half_size.y, 1.0f);
	}
	else
	{
		frame.type = INFINITE_PLANE;
		frame.scale = vec3(1.0f, 1.0f, 1.0f);
		frame.half_size = input->option.half_size;
	}
	frame.basis = *basis;
	frame.origin = input->center;
	return (build_primitive(&frame, &(object->primitive)));
}

static t_aabb	calc_plane_aabb(\
	t_input_plane const *input, t_mat3 const *basis)
{
	t_vec2	half_size;
	t_vec3	extent;

	half_size = input->option.half_size;
	extent = vec3(\
		mul_extent(half_size.u, fabsf(basis->row[X_AXIS].u)) \
			+ mul_extent(half_size.v, fabsf(basis->row[X_AXIS].v)), \
		mul_extent(half_size.u, fabsf(basis->row[Y_AXIS].u)) \
			+ mul_extent(half_size.v, fabsf(basis->row[Y_AXIS].v)), \
		mul_extent(half_size.u, fabsf(basis->row[Z_AXIS].u)) \
			+ mul_extent(half_size.v, fabsf(basis->row[Z_AXIS].v)) \
	);
	return (calc_aabb_from_extent(input->center, extent));
}
