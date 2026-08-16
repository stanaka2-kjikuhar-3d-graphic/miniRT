/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infinite_objects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 19:15:02 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/16 20:24:44 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

#include "ft_error.h"
#include "object.h"

#include "./infinite_objects_private.h"

static t_object const	**g_infinite_objects = NULL;
static size_t			g_infinite_count = 0;

bool	allocate_infinite_objects(size_t infinite_count)
{
	cleanup_infinite_objects();
	if (infinite_count == 0)
		return (true);
	g_infinite_objects = malloc(sizeof(t_object *) * infinite_count);
	if (g_infinite_objects == NULL)
	{
		print_errno();
		return (false);
	}
	g_infinite_count = infinite_count;
	return (true);
}

void	register_infinite_object(t_object const *object, size_t i)
{
	g_infinite_objects[i] = object;
}

t_object const	*get_infinite_object(size_t i)
{
	return (g_infinite_objects[i]);
}

size_t	get_infinite_object_count(void)
{
	return (g_infinite_count);
}

void	cleanup_infinite_objects(void)
{
	free(g_infinite_objects);
	g_infinite_objects = NULL;
	g_infinite_count = 0;
}
