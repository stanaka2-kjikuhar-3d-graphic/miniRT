/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_id.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 19:24:14 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/17 13:31:04 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>

#include "id.h"
#include "dynamic_array.h"

static t_dynamic_array	g_light_ids = (t_dynamic_array){\
										.type_size = sizeof(size_t) \
									};

bool	add_light_id(size_t index, t_id *light_id)
{
	light_id->id = g_light_ids.used;
	return (add_dynamic_array(&g_light_ids, &index));
}

size_t	get_light_index(t_id light_id)
{
	return ((*(size_t *)access_dynamic_array(&g_light_ids, light_id.id)));
}

void	cleanup_light_ids(void)
{
	cleanup_dynamic_array(&g_light_ids);
}
