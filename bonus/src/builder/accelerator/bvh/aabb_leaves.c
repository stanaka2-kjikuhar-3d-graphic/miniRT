/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aabb_leaves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 01:50:31 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/16 15:06:58 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

#include "ft_error.h"

#include "./bvh_private.h"

static t_aabb_leaf	*g_aabb_leaves = NULL;

bool	allocate_aabb_leaves(size_t bounded_aabb_count)
{
	cleanup_aabb_leaves();
	if (bounded_aabb_count == 0)
		return (true);
	g_aabb_leaves = malloc(sizeof(t_aabb_leaf) * bounded_aabb_count);
	if (g_aabb_leaves == NULL)
	{
		print_errno();
		return (false);
	}
	return (true);
}

void	register_aabb_leaf(t_aabb_leaf const *aabb_leaf, size_t i)
{
	g_aabb_leaves[i] = *aabb_leaf;
}

t_aabb_leaf const	*get_aabb_leaf(size_t i)
{
	return (&(g_aabb_leaves[i]));
}

void	swap_aabb_leaves(size_t a, size_t b)
{
	t_aabb_leaf	tmp;

	tmp = g_aabb_leaves[a];
	g_aabb_leaves[a] = g_aabb_leaves[b];
	g_aabb_leaves[b] = tmp;
}

void	cleanup_aabb_leaves(void)
{
	free(g_aabb_leaves);
	g_aabb_leaves = NULL;
}
