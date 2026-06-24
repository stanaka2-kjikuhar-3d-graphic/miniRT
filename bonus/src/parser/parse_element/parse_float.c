/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 19:25:28 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/24 00:20:48 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "ft_stdlib.h"
#include "ft_ctype.h"

#include "ft_error.h"

#include "../parser_private.h"

static bool	parse_floating_point(const char *element);

bool	parse_float(char const *element, float *value)
{
	if (!parse_floating_point(element))
		return (false);
	*value = (float)ft_strtod(element, (char **)&element);
	if (*element != '\0')
	{
		print_error(ERROR_FLOAT_CHARACTER);
		return (false);
	}
	return (true);
}

static bool	parse_floating_point(const char *element)
{
	if (*element == '-')
		++element;
	if (*element == '0' && (ft_tolower(*(element + 1)) == 'x'))
	{
		print_error(ERROR_FLOAT_CHARACTER);
		return (false);
	}
	if (*element == '0' && ft_isdigit(*(element + 1)))
	{
		print_error(ERROR_FLOAT_LEADING_ZERO);
		return (false);
	}
	if (*element == '.')
		++element;
	if (!ft_isdigit(*element))
	{
		print_error(ERROR_FLOAT_CHARACTER);
		return (false);
	}
	return (true);
}
