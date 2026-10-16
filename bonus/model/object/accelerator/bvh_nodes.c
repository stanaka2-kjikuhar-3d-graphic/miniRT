/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bvh_nodes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 22:11:43 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/13 23:46:19 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

#include "logger.h"

#include "bvh.h"

static t_bvh_node	*g_bvh_nodes = NULL;

bool	allocate_bvh_nodes(size_t count)
{
	if (count == 0)
		return (true);
	g_bvh_nodes = malloc((2 * count - 1) * sizeof(t_bvh_node));
	if (g_bvh_nodes == NULL)
	{
		print_log_errno(LOG_ERROR);
		return (false);
	}
	return (true);
}

void	register_bvh_node(t_bvh_node const *node, size_t i)
{
	g_bvh_nodes[i] = *node;
}

t_bvh_node const	*get_bvh_node(size_t i)
{
	return (&(g_bvh_nodes[i]));
}

void	cleanup_bvh_nodes(void)
{
	free(g_bvh_nodes);
	g_bvh_nodes = NULL;
}
