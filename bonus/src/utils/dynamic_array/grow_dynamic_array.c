/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grow_dynamic_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 22:53:11 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/26 00:44:28 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

#include "ft_error.h"

#include "ft_stdlib.h"

bool	grow_dynamic_array(void **array, size_t *capacity, size_t type_size)
{
	void	*tmp;

	if (*array == NULL)
		tmp = malloc(type_size);
	else
	{
		tmp = ft_realloc(\
				*array, type_size * *capacity, type_size * *capacity * 2);
	}
	if (tmp == NULL)
	{
		print_errno();
		return (false);
	}
	*array = tmp;
	if (*capacity == 0)
		*capacity = 1;
	else
		*capacity *= 2;
	return (true);
}
