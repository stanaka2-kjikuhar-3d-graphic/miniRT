/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_aabb_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 22:11:37 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/18 09:18:44 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "object.h"
#include "aabb.h"
#include "id.h"

#include "../object_private.h"

t_aabb_info const	*get_aabb_info(t_object_id id)
{
	t_object	*object;

	object = get_mutable_object(id);
	return (&(object->aabb_info));
}
