/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_material.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 22:10:45 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/18 09:58:26 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

#include "../object_private.h"

t_material const	*get_material(t_object_id id)
{
	t_object	*object;

	object = get_mutable_object(id);
	return (&(object->material));
}
