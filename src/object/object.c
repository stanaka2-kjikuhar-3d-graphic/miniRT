/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 21:05:41 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/12 01:16:36 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

#include "ft_stdlib.h"
#include "object.h"

static t_object	*g_objects;
static size_t	g_array_size;
static size_t	g_max_id;

bool	allocate_objects(size_t	add_count)
{
	if (g_objects == NULL)
	{
		g_array_size = add_count;
		g_objects = malloc(sizeof(t_object) * g_array_size);
		if (g_objects == NULL)
			return (false);
	}
	else
	{
		g_objects = ft_realloc(g_objects, \
						sizeof(t_object) * g_array_size, \
						sizeof(t_object) * (g_array_size + add_count));
		if (g_objects == NULL)
			return (false);
		g_array_size += add_count;
	}
	return (true);
}

bool	add_object(t_object *new)
{
	if (g_max_id == g_array_size)
	{
		if (!allocate_objects(16))
			return (false);
	}
	g_objects[g_max_id] = *new;
	g_objects[g_max_id].id = g_max_id;
	++g_max_id;
	return (true);
}

void	cleanup_objects(void)
{
	if (g_objects == NULL)
		return ;
	free(g_objects);
	g_objects = NULL;
	g_array_size = 0;
	g_max_id = 0;
}
