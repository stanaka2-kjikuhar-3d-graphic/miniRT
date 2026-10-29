/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_uv_pattern.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 22:08:24 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/18 10:00:47 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

#include "../../object_private.h"

t_uv_pattern const	*get_uv_pattern(t_object_id id)
{
	t_object	*object;

	object = get_mutable_object(id);
	return (&(object->uv.pattern));
}
