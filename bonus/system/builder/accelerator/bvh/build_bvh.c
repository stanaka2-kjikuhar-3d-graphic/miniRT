/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_bvh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 23:52:36 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/05 06:58:56 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

#include "config.h"
#include "aabb.h"
#include "vector.h"
#include "object.h"
#include "bvh.h"

#include "./bvh_private.h"

static size_t	count_bounded_aabb(void);
static t_aabb	calc_all_aabb(void);
static void		register_aabb_leaves(void);

bool	build_bvh(void)
{
	size_t	count;
	t_aabb	all_aabb;

	count = count_bounded_aabb();
	if (!allocate_bvh(count) || !allocate_aabb_leaves(count))
		return (false);
	if (count == 0)
		return (true);
	all_aabb = calc_all_aabb();
	register_aabb_leaves();
	build_binned_bvh((t_bvh_pos){.index = 0, .depth = 0}, 0, count, &all_aabb);
	return (true);
}

static size_t	count_bounded_aabb(void)
{
	size_t			bounded_count;
	size_t			object_count;
	size_t			i;
	t_object const	*object;

	bounded_count = 0;
	object_count = get_object_count();
	i = 0;
	while (i < object_count)
	{
		object = get_object(i);
		if (object->aabb_info.has_bounded_aabb)
			++bounded_count;
		++i;
	}
	return (bounded_count);
}

static t_aabb	calc_all_aabb(void)
{
	t_aabb			all_aabb;
	size_t			object_count;
	size_t			i;
	t_object const	*object;

	all_aabb = initial_aabb();
	object_count = get_object_count();
	i = 0;
	while (i < object_count)
	{
		object = get_object(i);
		if (object->aabb_info.has_bounded_aabb)
			all_aabb = union_aabb(all_aabb, object->aabb_info.aabb);
		++i;
	}
	return (all_aabb);
}

static void	register_aabb_leaves(void)
{
	t_aabb_leaf		aabb_leaf;
	size_t			leaf_count;
	size_t			object_count;
	size_t			i;
	t_object const	*object;

	leaf_count = 0;
	object = NULL;
	object_count = get_object_count();
	i = 0;
	while (i < object_count)
	{
		object = get_object(i);
		if (object->aabb_info.has_bounded_aabb)
		{
			aabb_leaf.aabb = object->aabb_info.aabb;
			aabb_leaf.centroid = object->aabb_info.centroid;
			aabb_leaf.object = object;
			register_aabb_leaf(&aabb_leaf, leaf_count++);
		}
		++i;
	}
}
