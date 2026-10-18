/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 21:05:41 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/18 08:55:01 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "object.h"
#include "dynamic_array.h"
#include "id.h"

#include "./object_private.h"

static t_dynamic_array	g_objects = (t_dynamic_array){\
										.type_size = sizeof(t_object) \
									};

t_dynamic_array	*get_mutable_object_array(void)
{
	return (&g_objects);
}

t_object const	*get_object(t_id id)
{
	return (access_dynamic_array(&g_objects, get_object_index(id)));
}

t_object	*get_mutable_object(t_id id)
{
	return (access_dynamic_array(&g_objects, get_object_index(id)));
}

t_object const	*get_object_by_index(size_t i)
{
	return (access_dynamic_array(&g_objects, i));
}
