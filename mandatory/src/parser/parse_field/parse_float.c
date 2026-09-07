/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 19:25:28 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/10 19:17:20 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>

#include "ft_stdlib.h"
#include "ft_ctype.h"

#include "ft_error.h"

#include "../parser_private.h"

static bool	parse_floating_point(const char *element);

bool	parse_float(char const *element, void *value)
{
	float *const	floating_point = (float *)value;

	if (!parse_floating_point(element))
		return (false);
	*floating_point = (float)ft_strtod(element, (char **)&element);
	if (*element != '\0')
	{
		print_field_error(ERROR_INVALID_CHARACTER, NULL);
		return (false);
	}
	if (isinf(*floating_point))
	{
		print_field_error(ERROR_MUST_BE_FINITE, HINT_FLOAT_FINITE);
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
		print_field_error(ERROR_INVALID_CHARACTER, NULL);
		return (false);
	}
	if (*element == '0' && ft_isdigit(*(element + 1)))
	{
		print_field_error(ERROR_LEADING_ZERO, NULL);
		return (false);
	}
	if (*element == '.')
		++element;
	if (!ft_isdigit(*element))
	{
		print_field_error(ERROR_INVALID_CHARACTER, NULL);
		return (false);
	}
	return (true);
}
