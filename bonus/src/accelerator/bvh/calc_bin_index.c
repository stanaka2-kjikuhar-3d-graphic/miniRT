/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_bin_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 15:20:00 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/16 18:38:59 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "config.h"
#include "accelerator.h"

#include "./bvh_private.h"

size_t	calc_bin_index(\
	t_aabb_leaf const *aabb_leaf, t_bin_partition const *partition)
{
	size_t	bin_index;

	bin_index = (size_t)((aabb_leaf->centroid[partition->axis] \
						- partition->range.min) / partition->delta);
	if (bin_index >= BVH_BIN)
		bin_index = BVH_BIN - 1;
	return (bin_index);
}
