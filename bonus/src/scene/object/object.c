/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 21:05:41 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/29 01:28:11 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

#include "ft_stdlib.h"

#include "ft_error.h"
#include "object.h"

static t_object	*g_objects;
static size_t	g_capacity;
static size_t	g_count;

static bool	allocate_objects(void);

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

bool	add_object(t_object const *object)
{
	if (g_count == g_capacity && !allocate_objects())
	{
		g_count = 0;
		return (false);
	}
	g_objects[g_count] = *object;
	++g_count;
	return (true);
}

static bool	allocate_objects(void)
{
	if (g_objects == NULL)
		g_objects = malloc(sizeof(t_object));
	else
	{
		g_objects = ft_reallocf(g_objects, \
						sizeof(t_object) * g_capacity, \
						sizeof(t_object) * (g_capacity * 2));
	}
	if (g_objects == NULL)
	{
		print_errno();
		g_capacity = 0;
		return (false);
	}
	if (g_capacity == 0)
		g_capacity = 1;
	else
		g_capacity *= 2;
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
