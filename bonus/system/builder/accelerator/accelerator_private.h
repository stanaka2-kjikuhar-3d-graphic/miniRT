/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accelerator_private.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 13:50:19 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/15 06:20:33 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACCELERATOR_PRIVATE_H
# define ACCELERATOR_PRIVATE_H

# include <stddef.h>

# include "vector.h"
# include "aabb.h"
# include "range.h"
# include "object.h"

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

size_t				calc_bin_index(t_object const *object, \
						t_bin_partition const *partition);
t_bin_partition		calc_best_bin_partition(size_t start, size_t count);
void				build_binned_bvh(t_bvh_pos pos, size_t start, \
						size_t count, t_aabb const *aabb);
void				add_leaf_node(size_t bvh_index, size_t start, \
						size_t count, t_aabb const *aabb);
float				calc_sah_cost(t_aabb const *left_aabb, size_t left_count, \
						t_aabb const *right_aabb, size_t right_count);

#endif
