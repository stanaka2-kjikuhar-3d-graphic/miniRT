/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sphere_aabb_info.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 22:31:51 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/18 09:57:43 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "aabb.h"
#include "vector.h"

#include "./object_aabb_info_private.h"

void	set_sphere_aabb_info(t_object_id id, t_sphere const *sphere)
{
	t_aabb_info	aabb_info;

	aabb_info.aabb = calc_aabb_from_extent(sphere->center, \
						vec3(sphere->radius, sphere->radius, sphere->radius));
	aabb_info.centroid = calc_aabb_centroid(&(aabb_info.aabb));
	aabb_info.has_bounded_aabb = has_bounded_aabb(&(aabb_info.aabb));
	set_aabb_info(id, &aabb_info);
}
