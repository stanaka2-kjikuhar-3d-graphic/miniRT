/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_best_bin_partition.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 15:39:17 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/16 19:25:22 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stddef.h>

#include "aabb.h"
#include "config.h"
#include "range.h"

#include "./bvh_private.h"

static t_range	calc_centroid_range(\
					size_t start, size_t count, enum e_axis axis);
static void		set_best_bin_partition(size_t start, size_t count, \
					t_bin_partition *current, t_bin_partition *best);
static void		set_bins(size_t start, size_t count, \
					t_bin *bins, t_bin_partition const *partition);
static void		set_left_and_right_bins(\
					t_bin const *bins, t_bin_partition *partition);

t_bin_partition	calc_best_bin_partition(size_t start, size_t count)
{
	t_bin_partition	best;
	t_bin_partition	current;
	t_range			range;
	enum e_axis		axis;

	best = (t_bin_partition){.cost = INFINITY};
	axis = X_AXIS;
	while (axis <= Z_AXIS)
	{
		range = calc_centroid_range(start, count, axis);
		if (axis == X_AXIS \
			|| current.range.max - current.range.min < range.max - range.min)
		{
			current.axis = axis;
			current.range = range;
		}
		++axis;
	}
	current.delta = (current.range.max - current.range.min) / (float)BVH_BIN;
	if (current.delta > 0.0f)
		set_best_bin_partition(start, count, &current, &best);
	return (best);
}

static t_range	calc_centroid_range(\
	size_t start, size_t count, enum e_axis axis)
{
	t_range				centroid_range;
	size_t				i;
	t_aabb_leaf const	*aabb_leaf;

	centroid_range = (t_range){.min = INFINITY, .max = -INFINITY};
	i = 0;
	while (i < count)
	{
		aabb_leaf = get_aabb_leaf(start + i);
		centroid_range.min \
			= fminf(centroid_range.min, aabb_leaf->centroid[axis]);
		centroid_range.max \
			= fmaxf(centroid_range.max, aabb_leaf->centroid[axis]);
		++i;
	}
	return (centroid_range);
}

static void	set_best_bin_partition(size_t start, size_t count, \
	t_bin_partition *current, t_bin_partition *best)
{
	t_bin	bins[BVH_BIN];

	set_bins(start, count, bins, current);
	current->index = 0;
	while (current->index < BVH_BIN - 1)
	{
		set_left_and_right_bins(bins, current);
		if (current->left.count > 0 && current->right.count > 0)
		{
			current->cost = calc_sah_cost(\
							&(current->left.aabb), current->left.count, \
							&(current->right.aabb), current->right.count);
			if (current->cost < best->cost)
				*best = *current;
		}
		++(current->index);
	}
}

static void	set_bins(size_t start, size_t count, \
	t_bin *bins, t_bin_partition const *partition)
{
	size_t				i;
	t_aabb_leaf const	*aabb_leaf;
	size_t				bin_index;

	i = 0;
	while (i < BVH_BIN)
		bins[i++] = (t_bin){.aabb = initial_aabb(), .count = 0};
	i = 0;
	while (i < count)
	{
		aabb_leaf = get_aabb_leaf(start + i);
		bin_index = calc_bin_index(aabb_leaf, partition);
		bins[bin_index].aabb \
			= union_aabb(bins[bin_index].aabb, aabb_leaf->aabb);
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
