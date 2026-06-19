/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 21:05:41 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/19 18:36:46 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

#include "ft_stdlib.h"
#include "ft_error.h"
#include "object.h"

static t_object	*g_objects;
static size_t	g_array_size;
static size_t	g_count;

t_object const	*get_objects(void)
{
	return (g_objects);
}

size_t	get_objects_count(void)
{
	return (g_count);
}

bool	allocate_objects(size_t add_count)
{
	if (g_objects == NULL)
	{
		g_objects = malloc(sizeof(t_object) * add_count);
		if (g_objects == NULL)
		{
			print_errno();
			return (false);
		}
		g_array_size = add_count;
	}
	else
	{
		g_objects = ft_reallocf(g_objects, \
						sizeof(t_object) * g_array_size, \
						sizeof(t_object) * (g_array_size + add_count));
		if (g_objects == NULL)
		{
			print_errno();
			return (false);
		}
		g_array_size += add_count;
	}
	return (true);
}

bool	add_object(t_object *new)
{
	if (g_count == g_array_size)
	{
		if (!allocate_objects(16))
			return (false);
	}
	g_objects[g_count] = *new;
	++g_count;
	return (true);
}

void	cleanup_objects(void)
{
	if (g_objects == NULL)
		return ;
	free(g_objects);
	g_objects = NULL;
	g_array_size = 0;
	g_count = 0;
}
