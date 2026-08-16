/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_dynamic_array.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 01:45:00 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/16 01:45:00 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

#include "ft_error.h"
#include "dynamic_array.h"

#include "ft_stdlib.h"

bool	allocate_dynamic_array(t_dynamic_array *dynamic_array, size_t new_size)
{
	void	*tmp;

	if (new_size <= dynamic_array->capacity)
		return (true);
	if (dynamic_array->data == NULL)
		tmp = malloc(dynamic_array->type_size * new_size);
	else
	{
		tmp = ft_realloc(dynamic_array->data, \
						dynamic_array->type_size * dynamic_array->capacity, \
						dynamic_array->type_size * new_size);
	}
	if (tmp == NULL)
	{
		print_errno();
		return (false);
	}
	dynamic_array->data = tmp;
	dynamic_array->capacity = new_size;
	return (true);
}
