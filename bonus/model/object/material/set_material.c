/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_material.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 23:16:10 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/09 07:18:32 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "object.h"

#include "../object_private.h"

void	set_material(size_t id, t_material const *material)
{
	t_object	*object;

	object = get_mutable_object(id);
	object->material = *material;
}
