/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_dynamic_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 22:49:03 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/16 00:39:35 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "ft_string.h"

#include "dynamic_array.h"

bool	add_dynamic_array(t_dynamic_array *dynamic_array, void const *data)
{
	if (dynamic_array->used == dynamic_array->capacity)
	{
		if (!grow_dynamic_array(dynamic_array))
			return (false);
	}
	ft_memcpy((char *)(dynamic_array->data) \
				+ (dynamic_array->used * dynamic_array->type_size), \
				data, dynamic_array->type_size);
	++(dynamic_array->used);
	return (true);
}
