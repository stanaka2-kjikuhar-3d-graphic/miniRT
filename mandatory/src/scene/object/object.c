/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 21:05:41 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/07 23:00:39 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

#include "ft_error.h"
#include "object.h"
#include "dynamic_array.h"

static t_dynamic_array	g_objects = (t_dynamic_array){\
										.type_size = sizeof(t_object) \
									};

bool	get_next_object(t_object const **object)
{
	t_object const	*last;

	if (g_objects.used == 0)
		return (false);
	last = access_dynamic_array(&g_objects, g_objects.used - 1);
	if (*object == last)
		return (false);
	if (*object == NULL)
		*object = (t_object const *)(g_objects.data);
	else
		++(*object);
	return (true);
}

t_object const	*get_object(size_t i)
{
	return (access_dynamic_array(&g_objects, i));
}

size_t	get_object_count(void)
{
	return (g_objects.used);
}

bool	create_object(t_object const *object)
{
	return (add_dynamic_array(&g_objects, object));
}

void	cleanup_objects(void)
{
	cleanup_dynamic_array(&g_objects);
}
