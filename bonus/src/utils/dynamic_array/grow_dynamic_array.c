/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grow_dynamic_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 22:53:11 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/15 22:48:42 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

#include "ft_error.h"
#include "dynamic_array.h"

#include "ft_stdlib.h"

bool	grow_dynamic_array(t_dynamic_array *dynamic_array)
{
	void	*tmp;

	if (dynamic_array->data == NULL)
		tmp = malloc(dynamic_array->type_size);
	else
	{
		tmp = ft_realloc(dynamic_array->data, \
						dynamic_array->type_size * dynamic_array->capacity, \
						dynamic_array->type_size * dynamic_array->capacity * 2);
	}
	if (tmp == NULL)
	{
		print_errno();
		return (false);
	}
	dynamic_array->data = tmp;
	if (dynamic_array->capacity == 0)
		dynamic_array->capacity = 1;
	else
		dynamic_array->capacity *= 2;
	return (true);
}
