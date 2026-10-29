/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_half_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 23:46:11 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/20 00:07:02 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "logger.h"

#include "../parser_private.h"

bool	parse_half_size(char const *element, float *half_size)
{
	float	size;

	if (!parse_float(element, &size))
		return (false);
	if (size <= 0.0f)
	{
		print_log_field(LOG_ERROR, ERROR_OUT_OF_RANGE);
		print_log_hint(LOG_ERROR, HINT_POSITIVE);
		return (false);
	}
	*half_size = size / 2.0f;
	if (*half_size == 0.0f)
	{
		print_log_field(LOG_ERROR, ERROR_TOO_SMALL);
		return (false);
	}
	return (true);
}
