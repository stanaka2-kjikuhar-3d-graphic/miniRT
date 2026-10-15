/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hyperboloid_aabb_info.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 22:31:57 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/08 22:19:56 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <math.h>

#include "object.h"
#include "aabb.h"
#include "vector.h"

#include "./object_aabb_info_private.h"

void	set_hyperboloid_aabb_info(size_t id, t_hyperboloid const *hyperboloid)
{
	t_aabb_info	aabb_info;
	t_vec3		disc_extent;
	t_vec3		top;
	t_vec3		bottom;

	disc_extent = vec3(\
		hyperboloid->cap_radius \
			* sqrtf(1.0f - hyperboloid->dir.x * hyperboloid->dir.x), \
		hyperboloid->cap_radius \
			* sqrtf(1.0f - hyperboloid->dir.y * hyperboloid->dir.y), \
		hyperboloid->cap_radius \
			* sqrtf(1.0f - hyperboloid->dir.z * hyperboloid->dir.z) \
	);
	top = vec3_add(hyperboloid->center, \
			vec3_scale(hyperboloid->half_height, hyperboloid->dir));
	bottom = vec3_sub(hyperboloid->center, \
			vec3_scale(hyperboloid->half_height, hyperboloid->dir));
	aabb_info.aabb = union_aabb(\
						calc_aabb_from_extent(top, disc_extent), \
						calc_aabb_from_extent(bottom, disc_extent) \
					);
	aabb_info.centroid = calc_aabb_centroid(&(aabb_info.aabb));
	aabb_info.has_bounded_aabb = has_bounded_aabb(&(aabb_info.aabb));
	set_aabb_info(id, &aabb_info);
}
