/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_id.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 06:28:03 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/18 09:26:18 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>

#include "object.h"
#include "dynamic_array.h"

static t_dynamic_array	g_object_ids = (t_dynamic_array){\
										.type_size = sizeof(size_t) \
									};

bool	add_object_id(size_t index, t_object_id *id)
{
	id->is_valid = true;
	id->id = g_object_ids.used;
	return (add_dynamic_array(&g_object_ids, &index));
}

size_t	get_object_index(t_object_id id)
{
	return ((*(size_t *)access_dynamic_array(&g_object_ids, id.id)));
}

void	cleanup_object_ids(void)
{
	cleanup_dynamic_array(&g_object_ids);
}
