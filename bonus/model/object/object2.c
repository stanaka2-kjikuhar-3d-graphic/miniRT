/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 22:51:42 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/18 08:58:20 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>

#include "object.h"
#include "dynamic_array.h"
#include "id.h"

#include "object_private.h"

size_t	get_object_count(void)
{
	return (get_mutable_object_array()->used);
}

bool	create_object(t_id *id)
{
	t_object	object;

	if (!add_object_id(get_mutable_object_array()->used, &(object.id)) \
			|| !add_dynamic_array(get_mutable_object_array(), &object))
	{
		return (false);
	}
	*id = object.id;
	return (true);
}

void	cleanup_objects(void)
{
	cleanup_dynamic_array(get_mutable_object_array());
}
