/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_half_height.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 23:46:11 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/26 00:46:03 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "ft_error.h"

#include "../parser_private.h"

bool	parse_half_height(char const *element, void *value)
{
	float *const	half_height = (float *)value;
	float			height;

	if (!parse_float(element, &height))
		return (false);
	if (height <= 0.0f)
	{
		print_field_error(ERROR_MUST_BE_POSITIVE, NULL);
		return (false);
	}
	*half_height = height / 2.0f;
	if (*half_height == 0.0f)
	{
		print_field_error(ERROR_TOO_SMALL, NULL);
		return (false);
	}
	return (true);
}
