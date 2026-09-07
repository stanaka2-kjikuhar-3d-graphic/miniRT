/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 15:48:24 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/07 22:50:35 by stanaka2         ###   ########.fr       */
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

static bool	set_plane_primitive(t_object *object, \
				t_input_plane const *input, t_mat3 const *basis);
static void	set_plane_aabb_info(t_aabb_info *aabb_info, \
				t_input_plane const *input, t_mat3 const *basis);

bool	create_plane(t_input_plane const *input)
{
	t_object	object;
	t_mat3		basis;

	object.albedo = input->albedo;
	basis = calc_onb(vec3_normalize(input->normal));
	if (!set_plane_primitive(&object, input, &basis))
		return (false);
	set_plane_aabb_info(&(object.aabb_info), input, &basis);
	return (create_object(&object));
}

static bool	set_plane_primitive(\
	t_object *object, t_input_plane const *input, t_mat3 const *basis)
{
	t_primitive_frame	frame;

	frame.type = INFINITE_PLANE;
	frame.scale = vec3(1.0f, 1.0f, 1.0f);
	frame.basis = *basis;
	frame.origin = input->center;
	return (build_primitive(&frame, &(object->primitive)));
}

static void	set_plane_aabb_info(\
	t_aabb_info *aabb_info, t_input_plane const *input, t_mat3 const *basis)
{
	t_vec3	extent;

	extent = vec3(\
		mul_extent(INFINITY, fabsf(basis->row[X_AXIS].u)) \
			+ mul_extent(INFINITY, fabsf(basis->row[X_AXIS].v)), \
		mul_extent(INFINITY, fabsf(basis->row[Y_AXIS].u)) \
			+ mul_extent(INFINITY, fabsf(basis->row[Y_AXIS].v)), \
		mul_extent(INFINITY, fabsf(basis->row[Z_AXIS].u)) \
			+ mul_extent(INFINITY, fabsf(basis->row[Z_AXIS].v)) \
	);
	aabb_info->aabb = calc_aabb_from_extent(input->center, extent);
	aabb_info->centroid = calc_aabb_centroid(&(aabb_info->aabb));
	aabb_info->has_bounded_aabb = has_bounded_aabb(&(aabb_info->aabb));
}
