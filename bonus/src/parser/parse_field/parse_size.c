/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 16:02:01 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/26 00:46:32 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "ft_error.h"

#include "../parser_private.h"

bool	parse_size(char const *element, void *value)
{
	float *const	size = (float *)value;

	if (!parse_float(element, size))
		return (false);
	if (*size <= 0.0f)
	{
		print_field_error(ERROR_OUT_OF_RANGE, HINT_POSITIVE);
		return (false);
	}
	return (true);
}
