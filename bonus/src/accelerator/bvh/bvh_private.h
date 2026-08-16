/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bvh_private.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 13:50:19 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/16 20:04:03 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BVH_PRIVATE_H
# define BVH_PRIVATE_H

# include <stddef.h>

# include "vector.h"
# include "aabb.h"
# include "range.h"
# include "accelerator.h"

# include "../accelerator_private.h"

typedef struct s_bvh_pos
{
	size_t	index;
	size_t	depth;
}	t_bvh_pos;

typedef struct s_bin
{
	t_aabb	aabb;
	size_t	count;
}	t_bin;

typedef struct s_bin_partition
{
	enum e_axis	axis;
	t_range		range;
	float		delta;
	size_t		index;
	t_bin		left;
	t_bin		right;
	float		cost;
}	t_bin_partition;

bool				allocate_bvh(size_t bounded_aabb_count);
void				register_bvh_node(t_bvh_node const *node, size_t i);
bool				allocate_aabb_leaves(size_t bounded_aabb_count);
void				register_aabb_leaf(t_aabb_leaf const *aabb_leaf, size_t i);
t_aabb_leaf const	*get_aabb_leaf(size_t i);
void				swap_aabb_leaves(size_t a, size_t b);
size_t				calc_bin_index(t_aabb_leaf const *aabb_leaf, \
						t_bin_partition const *partition);
t_bin_partition		calc_best_bin_partition(size_t start, size_t count);
void				build_binned_bvh(t_bvh_pos pos, size_t start, \
						size_t count, t_aabb const *aabb);
void				add_leaf_node(size_t bvh_index, size_t start, \
						size_t count, t_aabb const *aabb);
float				calc_sah_cost(t_aabb const *left_aabb, size_t left_count, \
						t_aabb const *right_aabb, size_t right_count);

#endif
