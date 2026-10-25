/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_id.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 20:32:51 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/25 22:06:23 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>

#include "material.h"
#include "dynamic_array.h"

static t_dynamic_array	g_material_ids = (t_dynamic_array){\
										.type_size = sizeof(size_t) \
									};

bool	add_material_id(size_t index, t_material_id *id)
{
	id->is_valid = true;
	id->id = g_material_ids.used;
	return (add_dynamic_array(&g_material_ids, &index));
}

size_t	get_material_index(t_material_id id)
{
	return ((*(size_t *)access_dynamic_array(&g_material_ids, id.id)));
}

void	cleanup_material_ids(void)
{
	cleanup_dynamic_array(&g_material_ids);
}
