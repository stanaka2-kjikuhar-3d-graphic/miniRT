/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_accelerator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 21:10:11 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/16 07:44:51 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>

#include "object.h"
#include "bvh.h"
#include "flat_list.h"

#include "./accelerator_private.h"

static void		count_each_object(void);
static void		partition_objects(void);
static t_aabb	calc_all_aabb(void);

bool	build_accelerator(void)
{
	t_aabb	all_aabb;

	count_each_object();
	if (!allocate_bvh_nodes(get_bvh_count()) \
		|| !allocate_bvh_leaves(get_bvh_count()) \
		|| !allocate_flat_list(get_flat_list_count()))
	{
		return (false);
	}
	partition_objects();
	if (get_bvh_count() > 0)
	{
		all_aabb = calc_all_aabb();
		build_binned_bvh(\
			(t_bvh_pos){.index = 0, .depth = 0}, 0, get_bvh_count(), &all_aabb);
	}
	return (true);
}

static void	count_each_object(void)
{
	size_t			bvh_count;
	size_t			flat_list_count;
	size_t			object_count;
	size_t			i;
	t_object const	*object;

	bvh_count = 0;
	flat_list_count = 0;
	object_count = get_object_count();
	i = 0;
	while (i < object_count)
	{
		object = get_object_by_index(i);
		if (object->aabb_info.has_bounded_aabb)
			++bvh_count;
		else
			++flat_list_count;
		++i;
	}
	set_bvh_count(bvh_count);
	set_flat_list_count(flat_list_count);
}

// add_flat_list() return true so that pre-allocated.
static void	partition_objects(void)
{
	size_t			bvh_count;
	size_t			flat_list_count;
	size_t			object_count;
	size_t			i;
	t_object const	*object;

	bvh_count = 0;
	flat_list_count = 0;
	object_count = get_object_count();
	i = 0;
	while (i < object_count)
	{
		object = get_object_by_index(i);
		if (object->aabb_info.has_bounded_aabb)
			register_bvh_leaf(bvh_count++, object->id);
		else
			register_flat_list(flat_list_count++, object->id);
		++i;
	}
}

static t_aabb	calc_all_aabb(void)
{
	t_aabb	all_aabb;
	size_t	count;
	size_t	i;

	all_aabb = initial_aabb();
	count = get_bvh_count();
	i = 0;
	while (i < count)
	{
		all_aabb = union_aabb(all_aabb, get_bvh_leaf(i)->aabb_info.aabb);
		++i;
	}
	return (all_aabb);
}
