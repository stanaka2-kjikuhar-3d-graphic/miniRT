/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_material.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 23:16:10 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/18 08:57:02 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "object.h"
#include "id.h"

#include "../object_private.h"

void	set_material(t_id id, t_material const *material)
{
	t_object	*object;

	object = get_mutable_object(id);
	object->material = *material;
}
