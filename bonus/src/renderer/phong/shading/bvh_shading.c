/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bvh_shading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 22:20:00 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/16 22:18:16 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>
#include <stddef.h>

#include "config.h"
#include "object.h"
#include "accelerator.h"

#include "../phong_private.h"

static bool	shadow_traverse_node(t_ray const *ray, float dist, \
				t_bvh_node const *node, float t);
static bool	shadow_traverse_children(\
				t_ray const *ray, float dist, t_bvh_node const *node);
static bool	shadow_traverse_leaves(t_ray const *ray, float dist, \
				size_t start, size_t count);

bool	bvh_shading(t_ray const *ray, float dist)
{
	t_bvh_node const	*root;
	float				t;

	root = get_bvh_node(0);
	if (root == NULL)
		return (false);
	t = calc_aabb_intersection(&(root->aabb), ray);
	return (shadow_traverse_node(ray, dist, root, t));
}

/* any-hit: stops at the first blocker instead of keeping the nearest one */
static bool	shadow_traverse_node(t_ray const *ray, float dist, \
	t_bvh_node const *node, float t)
{
	if (isnan(t) || dist <= t)
		return (false);
	if (node->has_leaf)
		return (shadow_traverse_leaves(ray, dist, \
				node->leaves.start, node->leaves.count));
	return (shadow_traverse_children(ray, dist, node));
}

static bool	shadow_traverse_children(\
	t_ray const *ray, float dist, t_bvh_node const *node)
{
	t_bvh_node const	*child[2];
	float				t[2];

	child[0] = get_bvh_node(node->branch.left);
	child[1] = get_bvh_node(node->branch.right);
	t[0] = calc_aabb_intersection(&(child[0]->aabb), ray);
	t[1] = calc_aabb_intersection(&(child[1]->aabb), ray);
	if (shadow_traverse_node(ray, dist, child[0], t[0]))
		return (true);
	return (shadow_traverse_node(ray, dist, child[1], t[1]));
}

static bool	shadow_traverse_leaves(t_ray const *ray, float dist, \
	size_t start, size_t count)
{
	t_aabb_leaf const	*leaf;
	float				t;

	while (count--)
	{
		leaf = get_aabb_leaf(start);
		t = calc_aabb_intersection(&(leaf->aabb), ray);
		if (t < dist)
		{
			t = calc_object_intersection(leaf->object, ray);
			if (0.0f < t && t < dist)
				return (true);
		}
		++start;
	}
	return (false);
}
