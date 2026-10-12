/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_paraboloid_aabb_info.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 22:31:55 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/08 22:20:04 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "object.h"
#include "aabb.h"
#include "vector.h"

#include "./object_aabb_info_private.h"

void	set_paraboloid_aabb_info(size_t id, t_primitive const *primitive)
{
	t_aabb_info	aabb_info;

	aabb_info.aabb = transform_aabb(&(primitive->to_world), \
						vec3(0.0f, 0.0f, 0.5f), vec3(1.0f, 1.0f, 0.5f));
	aabb_info.centroid = calc_aabb_centroid(&(aabb_info.aabb));
	aabb_info.has_bounded_aabb = has_bounded_aabb(&(aabb_info.aabb));
	set_aabb_info(id, &aabb_info);
}
