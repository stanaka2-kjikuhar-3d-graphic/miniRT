/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_material.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 22:10:45 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/17 01:15:46 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "object.h"
#include "id.h"

#include "../object_private.h"

t_material const	*get_material(t_id object_id)
{
	t_object	*object;

	object = get_mutable_object(object_id);
	return (&(object->material));
}
