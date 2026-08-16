/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bvh.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 22:11:43 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/16 21:32:03 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

#include "ft_error.h"

#include "./bvh_private.h"

static t_bvh_node	*g_bvh = NULL;

bool	allocate_bvh(size_t bounded_aabb_count)
{
	cleanup_bvh();
	if (bounded_aabb_count == 0)
		return (true);
	g_bvh = malloc((2 * bounded_aabb_count - 1) * sizeof(t_bvh_node));
	if (g_bvh == NULL)
	{
		print_errno();
		return (false);
	}
	return (true);
}

void	register_bvh_node(t_bvh_node const *node, size_t i)
{
	g_bvh[i] = *node;
}

t_bvh_node const	*get_bvh_node(size_t i)
{
	if (g_bvh == NULL)
		return (NULL);
	return (&(g_bvh[i]));
}

void	cleanup_bvh(void)
{
	free(g_bvh);
	g_bvh = NULL;
}
