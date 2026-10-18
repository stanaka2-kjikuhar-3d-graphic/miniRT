/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_uv_pattern.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 22:08:24 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/17 17:29:57 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "object.h"
#include "id.h"

#include "../../object_private.h"

t_uv_pattern const	*get_uv_pattern(t_id id)
{
	t_object	*object;

	object = get_mutable_object(id);
	return (&(object->uv.pattern));
}
