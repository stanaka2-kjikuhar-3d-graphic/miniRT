/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_uv_layout.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 22:09:14 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/18 09:59:58 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

#include "../../object_private.h"

t_uv_layout const	*get_uv_layout(t_object_id id)
{
	t_object	*object;

	object = get_mutable_object(id);
	return (&(object->uv.layout));
}
