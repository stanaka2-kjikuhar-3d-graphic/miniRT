/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flat_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 17:21:21 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/18 08:57:02 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "object.h"
#include "dynamic_array.h"
#include "id.h"

static t_dynamic_array	g_flat_list = (t_dynamic_array){\
										.type_size = sizeof(t_id) \
									};

bool	allocate_flat_list(size_t count)
{
	return (allocate_dynamic_array(&g_flat_list, count));
}

void	register_flat_list(size_t i, t_id id)
{
	*(t_id *)access_dynamic_array(&g_flat_list, i) = id;
}

bool	add_flat_list(t_id id)
{
	return (add_dynamic_array(&g_flat_list, &id));
}

t_object const	*get_flat_list_node(size_t i)
{
	return (get_object(*(t_id *)access_dynamic_array(&g_flat_list, i)));
}

void	cleanup_flat_list(void)
{
	cleanup_dynamic_array(&g_flat_list);
}
