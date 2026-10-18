/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_plane_aabb_info.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 22:31:52 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/18 09:18:44 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <math.h>

#include "object.h"
#include "aabb.h"
#include "vector.h"
#include "id.h"

#include "./object_aabb_info_private.h"

void	set_plane_aabb_info(t_object_id id, t_plane const *plane)
{
	t_aabb_info	aabb_info;
	t_vec2		half_size;
	t_mat3		basis;
	t_vec3		extent;

	half_size = plane->half_size;
	basis = mat3_build_onb(plane->normal);
	extent = vec3(\
		mul_extent(half_size.u, fabsf(basis.row[X_AXIS].u)) \
			+ mul_extent(half_size.v, fabsf(basis.row[X_AXIS].v)), \
		mul_extent(half_size.u, fabsf(basis.row[Y_AXIS].u)) \
			+ mul_extent(half_size.v, fabsf(basis.row[Y_AXIS].v)), \
		mul_extent(half_size.u, fabsf(basis.row[Z_AXIS].u)) \
			+ mul_extent(half_size.v, fabsf(basis.row[Z_AXIS].v)) \
	);
	aabb_info.aabb = calc_aabb_from_extent(plane->center, extent);
	aabb_info.centroid = calc_aabb_centroid(&(aabb_info.aabb));
	aabb_info.has_bounded_aabb = has_bounded_aabb(&(aabb_info.aabb));
	set_aabb_info(id, &aabb_info);
}
