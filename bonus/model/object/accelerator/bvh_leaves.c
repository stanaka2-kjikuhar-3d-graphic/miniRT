/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bvh_leaves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 19:38:32 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/16 07:37:16 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

#include "logger.h"
#include "object.h"
#include "id.h"

static t_id	*g_bvh_leaves = NULL;

bool	allocate_bvh_leaves(size_t count)
{
	if (count == 0)
		return (true);
	g_bvh_leaves = malloc(sizeof(size_t) * count);
	if (g_bvh_leaves == NULL)
	{
		print_log_errno(LOG_ERROR);
		return (false);
	}
	return (true);
}

void	register_bvh_leaf(size_t i, t_id object_id)
{
	g_bvh_leaves[i] = object_id;
}

t_object const	*get_bvh_leaf(size_t i)
{
	return (get_object(g_bvh_leaves[i]));
}

void	swap_bvh_leaves(size_t a, size_t b)
{
	t_id	tmp;

	tmp = g_bvh_leaves[a];
	g_bvh_leaves[a] = g_bvh_leaves[b];
	g_bvh_leaves[b] = tmp;
}

void	cleanup_bvh_leaves(void)
{
	free(g_bvh_leaves);
	g_bvh_leaves = NULL;
}
