/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 21:05:41 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/09 22:20:38 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>

#include "logger.h"
#include "object.h"
#include "dynamic_array.h"

#include "object_private.h"

static t_dynamic_array	g_objects = (t_dynamic_array){\
										.type_size = sizeof(t_object) \
									};

t_object const	*get_object(size_t id)
{
	return (access_dynamic_array(&g_objects, get_object_id(id)));
}

t_object	*get_mutable_object(size_t id)
{
	return (access_dynamic_array(&g_objects, get_object_id(id)));
}

size_t	get_object_count(void)
{
	return (g_objects.used);
}

bool	create_object(size_t *id)
{
	t_object	object;

	return (add_object_id(g_objects.used, id) \
			&& add_dynamic_array(&g_objects, &object));
}

void	cleanup_objects(void)
{
	cleanup_dynamic_array(&g_objects);
}
