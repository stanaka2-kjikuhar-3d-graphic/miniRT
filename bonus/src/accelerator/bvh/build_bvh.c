/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_bvh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 23:52:36 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/16 20:00:34 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

#include "config.h"
#include "aabb.h"
#include "vector.h"
#include "object.h"

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
	size_t			count;
	t_object const	*object;

	count = 0;
	object = NULL;
	while (get_next_object(&object))
	{
		if (object->has_bounded_aabb)
			++count;
	}
	return (count);
}

static t_aabb	calc_all_aabb(void)
{
	t_aabb			all_aabb;
	t_object const	*object;

	all_aabb = initial_aabb();
	object = NULL;
	while (get_next_object(&object))
	{
		if (object->has_bounded_aabb)
			all_aabb = union_aabb(all_aabb, object->aabb);
	}
	return (all_aabb);
}

static void	register_aabb_leaves(void)
{
	t_object const	*object;
	t_aabb_leaf		aabb_leaf;
	size_t			i;

	object = NULL;
	i = 0;
	while (get_next_object(&object))
	{
		if (object->has_bounded_aabb)
		{
			aabb_leaf.aabb = object->aabb;
			aabb_leaf.centroid[X_AXIS] = object->aabb_centroid.x;
			aabb_leaf.centroid[Y_AXIS] = object->aabb_centroid.y;
			aabb_leaf.centroid[Z_AXIS] = object->aabb_centroid.z;
			aabb_leaf.object = object;
			register_aabb_leaf(&aabb_leaf, i++);
		}
	}
}
