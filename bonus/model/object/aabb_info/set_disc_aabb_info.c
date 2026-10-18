/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_disc_aabb_info.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 22:31:47 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/18 09:57:18 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "object.h"
#include "aabb.h"
#include "vector.h"

#include "./object_aabb_info_private.h"

void	set_disc_aabb_info(t_object_id id, t_disc const *disc)
{
	t_aabb_info	aabb_info;
	t_vec3		extent;

	extent = vec3(\
		disc->radius * sqrtf(1.0f - disc->normal.x * disc->normal.x), \
		disc->radius * sqrtf(1.0f - disc->normal.y * disc->normal.y), \
		disc->radius * sqrtf(1.0f - disc->normal.z * disc->normal.z) \
	);
	aabb_info.aabb = calc_aabb_from_extent(disc->center, extent);
	aabb_info.centroid = calc_aabb_centroid(&(aabb_info.aabb));
	aabb_info.has_bounded_aabb = has_bounded_aabb(&(aabb_info.aabb));
	set_aabb_info(id, &aabb_info);
}
