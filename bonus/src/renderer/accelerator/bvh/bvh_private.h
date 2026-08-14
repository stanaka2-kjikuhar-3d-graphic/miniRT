/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bvh_private.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 13:50:19 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/15 03:45:53 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BVH_PRIVATE_H
# define BVH_PRIVATE_H

# include <stddef.h>

# include "vector.h"
# include "aabb.h"

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

float	calc_sah_cost(t_aabb const *left_aabb, size_t left_count, \
			t_aabb const *right_aabb, size_t right_count);

#endif