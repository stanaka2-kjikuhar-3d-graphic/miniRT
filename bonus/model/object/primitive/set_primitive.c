/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_primitive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 22:20:17 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/18 08:57:02 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "primitive.h"
#include "object.h"
#include "id.h"

#include "../object_private.h"
#include "./object_primitive_private.h"

void	set_primitive(t_id id, t_primitive const *primitive)
{
	t_object	*object;

	object = get_mutable_object(id);
	object->primitive = *primitive;
}
