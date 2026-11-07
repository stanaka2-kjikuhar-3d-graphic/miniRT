/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 20:32:04 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/26 21:09:58 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material.h"
#include "dynamic_array.h"

#include "./material_private.h"

static t_dynamic_array	g_materials = (t_dynamic_array){\
										.type_size = sizeof(t_material) \
									};

t_material const	*get_material(t_material_id id)
{
	return (access_dynamic_array(&g_materials, get_material_index(id)));
}

t_material	*get_mutable_material(t_material_id id)
{
	return (access_dynamic_array(&g_materials, get_material_index(id)));
}

bool	create_material(t_material_id *id)
{
	t_material	material;

	if (!add_material_id(g_materials.used, &(material.id)) \
			|| !add_dynamic_array(&g_materials, &material))
	{
		return (false);
	}
	*id = material.id;
	return (true);
}

void	cleanup_materials(void)
{
	cleanup_dynamic_array(&g_materials);
}
