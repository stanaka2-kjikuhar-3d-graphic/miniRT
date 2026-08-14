/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_binned_bvh.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 12:36:35 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/15 04:14:09 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>
#include <stddef.h>

#include "aabb.h"
#include "config.h"
#include "range.h"

#include "./bvh_private.h"
#include "../renderer_private.h"

static t_bin_partition	calc_best_bin_partition(\
							t_aabb_leaf const *aabb_leaves, size_t count);
static void				set_bins(t_aabb_leaf const *aabb_leaves, size_t count, \
							t_bin *bins, t_bin_partition const *partition);
static t_range			calc_centroid_range(t_aabb_leaf const *aabb_leaves, 
							size_t count, enum e_axis axis);
static void				set_left_and_right_bins(\
							t_bin const *bins, t_bin_partition *partition);

t_bvh_node const	*build_binned_bvh(t_bvh_node **bvh, \
	t_aabb_leaf *aabb_leaves, size_t count, t_aabb const *aabb)
{
	t_bin_partition	best;
	t_bvh_node		*branch_node;

	if (count <= BVH_LEAF_MAX)
		return (add_leaf_node(bvh, aabb_leaves, count, aabb));
	best = calc_best_bin_partition(aabb_leaves, count);
	if (best.cost == INFINITY)
		return (add_leaf_node(bvh, aabb_leaves, count, aabb));
	separate_left_and_right_bins(aabb_leaves, count, &best);
	branch_node = (*bvh)++;
	branch_node->aabb = *aabb;
	branch_node->has_leaf = false;
	branch_node->branch.left \
		= build_binned_bvh(bvh, aabb_leaves, \
								best.left.count, &(best.left.aabb));
	branch_node->branch.right \
		= build_binned_bvh(bvh, aabb_leaves + best.left.count, \
								best.right.count, &(best.right.aabb));
	return (branch_node);
}

static void	separate_left_and_right_bins(\
	t_aabb_leaf *aabb_leaves, size_t count, t_bin_partition const *partition)
{
	
}

static t_bin_partition	calc_best_bin_partition(\
	t_aabb_leaf const *aabb_leaves, size_t count)
{
	t_bin			bins[BVH_BIN];
	t_bin_partition	best;
	t_bin_partition	current;

	best.cost = INFINITY;
	current.axis = X_AXIS;
	while (current.axis <= Z_AXIS)
	{
		current.range = calc_centroid_range(aabb_leaves, count, current.axis);
		current.delta = (current.range.max - current.range.min) / (float)BVH_BIN;
		set_bins(aabb_leaves, count, bins, &current);
		current.index = 0;
		while (current.index < BVH_BIN - 1)
		{
			set_left_and_right_bins(bins, &current);
			current.cost = calc_sah_cost(\
							&(current.left.aabb), current.left.count, \
							&(current.right.aabb), current.right.count);
			if (current.cost < best.cost)
				best = current;
			++(current.index);
		}
		++(current.axis);
	}
	return (best);
}

static t_range	calc_centroid_range(\
	t_aabb_leaf const *aabb_leaves, size_t count, enum e_axis axis)
{
	t_range	centroid_range;
	size_t	i;

	centroid_range = (t_range){.min = INFINITY, .max = -INFINITY};
	i = 0;
	while (i < count)
	{
		centroid_range.min \
			= fminf(centroid_range.min, aabb_leaves[i].centroid[axis]);
		centroid_range.max \
			= fmaxf(centroid_range.max, aabb_leaves[i].centroid[axis]);
		++i;
	}
	return (centroid_range);
}

static void	set_bins(t_aabb_leaf const *aabb_leaves, size_t count, \
	t_bin *bins, t_bin_partition const *partition)
{
	size_t	i;
	size_t	bin_index;

	i = 0;
	while (i < BVH_BIN)
		bins[i++] = (t_bin){.aabb = initial_aabb(), .count = 0};
	i = 0;
	while (i < count)
	{
		bin_index = (size_t)((aabb_leaves[i].centroid[partition->axis] \
							- partition->range.min) / partition->delta);
		if (bin_index == BVH_BIN)
			bin_index = BVH_BIN - 1;
		bins[bin_index].aabb \
			= union_aabb(bins[bin_index].aabb, aabb_leaves[i].aabb);
		++(bins[bin_index].count);
		++i;
	}
}

static void	set_left_and_right_bins(\
	t_bin const *bins, t_bin_partition *partition)
{
	size_t	i;

	partition->left = (t_bin){.aabb = initial_aabb(), .count = 0};
	partition->right = (t_bin){.aabb = initial_aabb(), .count = 0};
	i = 0;
	while (i < BVH_BIN)
	{
		if (bins[i].count > 0)
		{
			if (i <= partition->index)
			{
				partition->left.aabb \
					= union_aabb(partition->left.aabb, bins[i].aabb);
				partition->left.count += bins[i].count;
			}
			else
			{
				partition->right.aabb \
					= union_aabb(partition->right.aabb, bins[i].aabb);
				partition->right.count += bins[i].count;
			}
		}
		++i;
	}
}

