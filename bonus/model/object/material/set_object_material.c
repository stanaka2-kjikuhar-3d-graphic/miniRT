/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_object_material.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 22:16:28 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/25 22:16:33 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "material.h"

#include "./material_private.h"
#include "../object_private.h"

bool	set_object_material(t_object_id id, t_material const *material)
{
	t_object	*object;

	object = get_mutable_object(id);
	if (!create_material(&(object->material_id)))
		return (false);
	*get_mutable_material(object->material_id) = *material;
	return (true);
}
