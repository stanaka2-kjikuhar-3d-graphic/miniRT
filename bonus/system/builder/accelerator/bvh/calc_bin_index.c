/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_bin_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 15:20:00 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/15 06:15:29 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "config.h"
#include "object.h"

#include "../accelerator_private.h"

size_t	calc_bin_index(t_object const *object, t_bin_partition const *partition)
{
	size_t	bin_index;

	bin_index = (size_t)((object->aabb_info.centroid.e[partition->axis] \
							- partition->range.min) / partition->delta);
	if (bin_index >= BVH_BIN)
		bin_index = BVH_BIN - 1;
	return (bin_index);
}
