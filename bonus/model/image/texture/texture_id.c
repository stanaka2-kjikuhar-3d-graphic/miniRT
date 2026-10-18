/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_id.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 13:28:59 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/18 08:07:29 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>

#include "dynamic_array.h"
#include "texture.h"

static t_dynamic_array	g_texture_ids = (t_dynamic_array){\
										.type_size = sizeof(size_t) \
									};

bool	add_texture_id(size_t index, t_texture_id *id)
{
	id->is_valid = true;
	id->id = g_texture_ids.used;
	return (add_dynamic_array(&g_texture_ids, &index));
}

size_t	get_texture_index(t_texture_id id)
{
	return ((*(size_t *)access_dynamic_array(&g_texture_ids, id.id)));
}

void	cleanup_texture_ids(void)
{
	cleanup_dynamic_array(&g_texture_ids);
}
