/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 21:05:41 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/14 01:30:11 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

#include "ft_error.h"
#include "object.h"
#include "dynamic_array.h"

static t_object	*g_objects;
static size_t	g_capacity;
static size_t	g_count;

bool	get_next_object(t_object const **object)
{
	if (g_count == 0 || *object == &(g_objects[g_count - 1]))
		return (false);
	if (*object == NULL)
		*object = &(g_objects[0]);
	else
		++(*object);
	return (true);
}

t_object const	*get_object(size_t i)
{
	return (&g_objects[i]);
}

size_t	get_object_count(void)
{
	return (g_count);
}

bool	create_object(t_object const *object)
{
	if (g_count == g_capacity && !grow_dynamic_array(\
						(void **)(&g_objects), &g_capacity, sizeof(t_object)))
	{
		return (false);
	}
	g_objects[g_count] = *object;
	++g_count;
	return (true);
}

void	cleanup_objects(void)
{
	if (g_objects == NULL)
		return ;
	free(g_objects);
	g_objects = NULL;
	g_capacity = 0;
	g_count = 0;
}
