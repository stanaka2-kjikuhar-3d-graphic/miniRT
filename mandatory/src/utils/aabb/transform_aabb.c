/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_aabb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 03:31:39 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/07 22:43:19 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "aabb.h"
#include "matrix.h"
#include "vector.h"

static t_vec3	transform_extent(t_mat4 const *m, t_vec3 extent);

t_aabb	transform_aabb(t_mat4 const *to_world, t_vec3 center, t_vec3 extent)
{
	t_vec3	world_center;
	t_vec3	world_extent;

	world_center = mat4_transform_point(to_world, center);
	world_extent = transform_extent(to_world, extent);
	return (calc_aabb_from_extent(world_center, world_extent));
}

static t_vec3	transform_extent(t_mat4 const *m, t_vec3 extent)
{
	t_vec3	world_extent;

	world_extent.x = fabsf(m->m[0][0]) * extent.x + fabsf(m->m[0][1]) * extent.y
		+ fabsf(m->m[0][2]) * extent.z;
	world_extent.y = fabsf(m->m[1][0]) * extent.x + fabsf(m->m[1][1]) * extent.y
		+ fabsf(m->m[1][2]) * extent.z;
	world_extent.z = fabsf(m->m[2][0]) * extent.x + fabsf(m->m[2][1]) * extent.y
		+ fabsf(m->m[2][2]) * extent.z;
	return (world_extent);
}
