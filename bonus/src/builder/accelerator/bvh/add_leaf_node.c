/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_leaf_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 13:44:12 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/16 21:54:47 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "./bvh_private.h"

void	add_leaf_node(size_t bvh_index, size_t start, size_t count, \
	t_aabb const *aabb)
{
	t_bvh_node	leaf_node;

	leaf_node.aabb = *aabb;
	leaf_node.has_leaf = true;
	leaf_node.leaves.start = start;
	leaf_node.leaves.count = count;
	register_bvh_node(&leaf_node, bvh_index);
}
