/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_leaf_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 13:44:12 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/15 04:13:13 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "../renderer_private.h"

t_bvh_node const	*add_leaf_node(t_bvh_node **bvh, \
	t_aabb_leaf *aabb_leaves, size_t count, t_aabb const *aabb)
{
	t_bvh_node	*leaf_node;

	leaf_node = (*bvh)++;
	leaf_node->aabb = *aabb;
	leaf_node->has_leaf = true;
	leaf_node->leaves.start = aabb_leaves;
	leaf_node->leaves.count = count;
	return (leaf_node);
}
