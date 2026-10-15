/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_primitive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 22:09:56 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/09 22:11:27 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "object.h"
#include "primitive.h"

#include "../object_private.h"

t_primitive const	*get_primitive(size_t id)
{
	t_object	*object;

	object = get_mutable_object(id);
	return (&(object->primitive));
}
