/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 00:01:03 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/24 00:39:50 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "ft_stdlib.h"
#include "ft_ctype.h"

#include "logger.h"

#include "../parser_private.h"

static bool	parse_format(const char *element);

bool	parse_long(char const *element, void *value)
{
	long *const	num = (long *)value;

	if (!parse_format(element))
		return (false);
	*num = ft_strtol(element, NULL, 10);
	return (true);
}

static bool	parse_format(const char *element)
{
	if (*element == '-')
		++element;
	if (*element == '0' && ft_isdigit(*(element + 1)))
	{
		print_log_field(LOG_ERROR, ERROR_LEADING_ZERO);
		return (false);
	}
	if (!ft_isdigit(*element))
	{
		print_log_field(LOG_ERROR, ERROR_INVALID_CHARACTER);
		return (false);
	}
	while (ft_isdigit(*element))
		++element;
	if (*element != '\0')
	{
		print_log_field(LOG_ERROR, ERROR_INVALID_CHARACTER);
		return (false);
	}
	return (true);
}
