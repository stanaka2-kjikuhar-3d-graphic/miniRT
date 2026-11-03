/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bvh_shading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 22:20:00 by stanaka2          #+#    #+#             */
/*   Updated: 2026/11/03 20:59:59 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>
#include <stddef.h>

#include "object.h"
#include "ray.h"
#include "bvh.h"
#include "range.h"

#include "../intersection_private.h"

static bool	shadow_traverse_node(t_ray const *ray, t_range range, \
				t_bvh_node const *node);
static bool	shadow_traverse_leaves(t_ray const *ray, t_range range, \
				size_t start, size_t count);

bool	bvh_shading(t_ray const *ray, t_range range)
{
	t_bvh_node const	*root;
	float				t;

	if (get_bvh_count() == 0)
		return (false);
	root = get_bvh_node(0);
	if (root == NULL)
		return (false);
	t = calc_aabb_intersection(&(root->aabb), ray);
	if (isnan(t) || range.max < t)
		return (false);
	return (shadow_traverse_node(ray, range, root));
}

/* any-hit: stops at the first blocker instead of keeping the nearest one */
static bool	shadow_traverse_node(\
	t_ray const *ray, t_range range, t_bvh_node const *node)
{
	t_bvh_node const	*left;
	t_bvh_node const	*right;
	float				t;

	if (node->has_leaf)
	{
		return (shadow_traverse_leaves(ray, range, \
					node->leaves.start, node->leaves.count));
	}
	else
	{
		left = get_bvh_node(node->branch.left);
		t = calc_aabb_intersection(&(left->aabb), ray);
		if (t <= range.max && shadow_traverse_node(ray, range, left))
			return (true);
		right = get_bvh_node(node->branch.right);
		t = calc_aabb_intersection(&(right->aabb), ray);
		return (t <= range.max && shadow_traverse_node(ray, range, right));
	}
}

static bool	shadow_traverse_leaves(t_ray const *ray, t_range range, \
	size_t start, size_t count)
{
	t_object const	*object;
	float			t;

	while (count--)
	{
		object = get_bvh_leaf(start);
		t = calc_aabb_intersection(&(object->aabb_info.aabb), ray);
		if (t <= range.max)
		{
			t = calc_object_intersection(object, ray);
			if (range.min < t && t <= range.max)
				return (true);
		}
		++start;
	}
	return (false);
}
