/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_uv_layout.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 22:09:14 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/18 08:57:02 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "object.h"
#include "id.h"

#include "../../object_private.h"

t_uv_layout const	*get_uv_layout(t_id id)
{
	t_object	*object;

	object = get_mutable_object(id);
	return (&(object->uv.layout));
}
