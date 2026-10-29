/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_primitive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 22:09:56 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/18 09:58:38 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "primitive.h"

#include "../object_private.h"

t_primitive const	*get_primitive(t_object_id id)
{
	t_object	*object;

	object = get_mutable_object(id);
	return (&(object->primitive));
}
