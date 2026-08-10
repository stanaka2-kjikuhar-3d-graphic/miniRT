/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_half_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 23:46:11 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/10 17:49:45 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "ft_error.h"

#include "../parser_private.h"

bool	parse_half_size(char const *element, void *value)
{
	float *const	half_size = (float *)value;
	float			size;

	if (!parse_float(element, &size))
		return (false);
	if (size <= 0.0f)
	{
		print_field_error(ERROR_OUT_OF_RANGE, HINT_POSITIVE);
		return (false);
	}
	*half_size = size / 2.0f;
	if (*half_size == 0.0f)
	{
		print_field_error(ERROR_TOO_SMALL, NULL);
		return (false);
	}
	return (true);
}
