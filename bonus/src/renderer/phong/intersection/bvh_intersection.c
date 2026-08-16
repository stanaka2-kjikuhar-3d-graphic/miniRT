/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bvh_intersection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 20:29:13 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/16 22:07:58 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <math.h>

#include "config.h"
#include "object.h"
#include "accelerator.h"

#include "../phong_private.h"

static void	traverse_bvh_branch(t_hit *hit, t_ray const *ray, \
				t_bvh_node const *branch);
static void	traverse_bvh_branch_front_to_back(t_hit *hit, t_ray const *ray, \
				t_bvh_node const *left, t_bvh_node const *right);
static void	traverse_bvh_leaves(\
				t_hit *hit, t_ray const *ray, size_t start, size_t count);

void	bvh_intersection(t_hit *hit, t_ray const *ray)
{
	t_bvh_node const	*branch;
	float				t;

	branch = get_bvh_node(0);
	if (branch == NULL)
		return ;
	t = calc_aabb_intersection(&(branch->aabb), ray);
	if (isnan(t) || hit->t < t)
		return ;
	traverse_bvh_branch(hit, ray, branch);
}

static void	traverse_bvh_branch(\
	t_hit *hit, t_ray const *ray, t_bvh_node const *branch)
{
	if (branch->has_leaf)
	{
		traverse_bvh_leaves(\
			hit, ray, branch->leaves.start, branch->leaves.count);
	}
	else
	{
		traverse_bvh_branch_front_to_back(hit, ray, \
								get_bvh_node(branch->branch.left), \
								get_bvh_node(branch->branch.right));
	}
}

static void	traverse_bvh_branch_front_to_back(t_hit *hit, t_ray const *ray, \
	t_bvh_node const *left, t_bvh_node const *right)
{
	float	t_left;
	float	t_right;

	t_left = calc_aabb_intersection(&(left->aabb), ray);
	t_right = calc_aabb_intersection(&(right->aabb), ray);
	if (t_left < t_right)
	{
		if (t_left <= hit->t)
			traverse_bvh_branch(hit, ray, left);
		if (t_right <= hit->t)
			traverse_bvh_branch(hit, ray, right);
	}
	else
	{
		if (t_right <= hit->t)
			traverse_bvh_branch(hit, ray, right);
		if (t_left <= hit->t)
			traverse_bvh_branch(hit, ray, left);
	}
}

static void	traverse_bvh_leaves(\
	t_hit *hit, t_ray const *ray, size_t start, size_t count)
{
	t_object const	*object;
	float			t;

	while (count--)
	{
		object = get_aabb_leaf(start)->object;
		t = calc_aabb_intersection(&(object->aabb), ray);
		if (t <= hit->t)
		{
			t = calc_object_intersection(object, ray);
			if (EPSILON < t && t < hit->t)
			{
				hit->object = object;
				hit->t = t;
			}
		}
		++start;
	}
}
