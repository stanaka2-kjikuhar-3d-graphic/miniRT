/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_binned_bvh.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 12:36:35 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/15 06:13:12 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stddef.h>

#include "aabb.h"
#include "config.h"
#include "bvh.h"

#include "../accelerator_private.h"

static void	separate_left_and_right_bins(size_t start, size_t count, \
					t_bin_partition const *partition);

void	build_binned_bvh(\
	t_bvh_pos bvh, size_t start, size_t count, t_aabb const *aabb)
{
	t_bin_partition	best;
	t_bvh_node		branch_node;

	++(bvh.depth);
	best.cost = INFINITY;
	if (count > BVH_LEAF_MAX && bvh.depth < BVH_MAX_DEPTH)
		best = calc_best_bin_partition(start, count);
	if (best.cost == INFINITY)
	{
		add_leaf_node(bvh.index, start, count, aabb);
		return ;
	}
	separate_left_and_right_bins(start, count, &best);
	branch_node.aabb = *aabb;
	branch_node.has_leaf = false;
	branch_node.branch.left = bvh.index + 1;
	branch_node.branch.right = bvh.index + 2 * best.left.count;
	register_bvh_node(&branch_node, bvh.index);
	bvh.index = branch_node.branch.left;
	build_binned_bvh(bvh, start, best.left.count, &(best.left.aabb));
	bvh.index = branch_node.branch.right;
	build_binned_bvh(bvh, start + best.left.count, best.right.count, \
						&(best.right.aabb));
}

static void	separate_left_and_right_bins(size_t start, size_t count, \
	t_bin_partition const *partition)
{
	size_t	left;
	size_t	right;

	left = start;
	right = start + count - 1;
	while (left < right)
	{
		while (calc_bin_index(get_bvh_leaf(left), partition) \
				<= partition->index)
			++left;
		while (calc_bin_index(get_bvh_leaf(right), partition) \
				> partition->index)
			--right;
		if (left < right)
			swap_bvh_leaves(left++, right--);
	}
}
