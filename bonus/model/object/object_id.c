/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_id.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 06:28:03 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/06 20:50:10 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>

#include "id.h"
#include "dynamic_array.h"

static t_dynamic_array	g_object_ids = (t_dynamic_array){\
										.type_size = sizeof(t_id) \
									};

bool	add_object_id(size_t index, size_t *id)
{
	t_id	new_id;

	new_id.index = index;
	*id = g_object_ids.used;
	return (add_dynamic_array(&g_object_ids, &new_id));
}

size_t	get_object_id(size_t id)
{
	return (((t_id *)access_dynamic_array(&g_object_ids, id))->index);
}

void	cleanup_object_ids(void)
{
	cleanup_dynamic_array(&g_object_ids);
}
