/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_bvh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 23:52:36 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/15 05:14:46 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

#include "config.h"
#include "aabb.h"
#include "vector.h"

#include "./bvh_private.h"
#include "../renderer_private.h"

bool	build_bvh(void)
{
	t_bvh_node		*bvh;
	t_aabb_leaf		*aabb_leaves;
	size_t			count;
	t_aabb			all_aabb;
	t_object const	*object;
	size_t			i;

	count = get_object_count();
	bvh = malloc((2 * count - 1) * sizeof(t_bvh_node));
	if (bvh == NULL)
		return (false);
	aabb_leaves = malloc(count * sizeof(t_aabb_leaf));
	if (aabb_leaves == NULL)
	{
		free(bvh);
		return (false);
	}
	all_aabb = initial_aabb();
	object = NULL;
	i = 0;
	while (get_next_object(&object))
	{
		if (object->has_bounded_aabb == false)
			--count;
		else
		{
			all_aabb = union_aabb(all_aabb, object->aabb);
			aabb_leaves[i].aabb = object->aabb;
			aabb_leaves[i].centroid[X_AXIS] = object->aabb_centroid.x;
			aabb_leaves[i].centroid[Y_AXIS] = object->aabb_centroid.y;
			aabb_leaves[i].centroid[Z_AXIS] = object->aabb_centroid.z;
			aabb_leaves[i].object = object;
			++i;
		}
	}
	build_binned_bvh(&bvh, aabb_leaves, count, & all_aabb);
	return (true);
}


