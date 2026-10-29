/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cone_aabb_info.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 22:32:02 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/18 09:57:10 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "object.h"
#include "aabb.h"
#include "vector.h"

#include "./object_aabb_info_private.h"

void	set_cone_aabb_info(t_object_id id, t_cone const *cone)
{
	t_aabb_info	aabb_info;
	t_vec3		disc_extent;
	t_aabb		disc_aabb;
	t_vec3		vertex;
	t_aabb		vertex_aabb;

	disc_extent = vec3(\
		cone->radius * sqrtf(1.0f - cone->dir.x * cone->dir.x), \
		cone->radius * sqrtf(1.0f - cone->dir.y * cone->dir.y), \
		cone->radius * sqrtf(1.0f - cone->dir.z * cone->dir.z) \
	);
	disc_aabb = calc_aabb_from_extent(cone->center, disc_extent);
	vertex = vec3_add(cone->center, vec3_scale(cone->height, cone->dir));
	vertex_aabb = calc_aabb_from_extent(vertex, vec3(0.0f, 0.0f, 0.0f));
	aabb_info.aabb = union_aabb(disc_aabb, vertex_aabb);
	aabb_info.centroid = calc_aabb_centroid(&(aabb_info.aabb));
	aabb_info.has_bounded_aabb = has_bounded_aabb(&(aabb_info.aabb));
	set_aabb_info(id, &aabb_info);
}
