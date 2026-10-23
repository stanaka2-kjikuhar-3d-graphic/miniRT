/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vec3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 09:47:15 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/23 13:39:13 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "ft_stdlib.h"
#include "ft_ctype.h"

#include "vector.h"
#include "logger.h"

#include "../parser_private.h"

static bool	parse_axis(const char *element);
static bool	check_separator(const char *element, enum e_axis axis);

bool	parse_vec3(char const *element, t_vec3 *vector)
{
	enum e_axis	axis;

	axis = X_AXIS;
	while (axis <= Z_AXIS)
	{
		if (!parse_axis(element))
			return (false);
		vector->e[axis] = (float)ft_strtod(element, (char **)&element);
		if (!check_separator(element, axis))
			return (false);
		++element;
		++axis;
	}
	return (true);
}

static bool	check_separator(const char *element, enum e_axis axis)
{
	if (((axis == X_AXIS || axis == Y_AXIS) && *element == '\0') \
		|| (axis == Z_AXIS && *element == ','))
	{
		print_log_field(LOG_ERROR, ERROR_INVALID_FORMAT);
		print_log_hint(LOG_ERROR, HINT_VECTOR);
		return (false);
	}
	if (((axis == X_AXIS || axis == Y_AXIS) && *element != ',') \
		|| (axis == Z_AXIS && *element != '\0'))
	{
		print_log_field(LOG_ERROR, ERROR_INVALID_CHARACTER);
		return (false);
	}
	return (true);
}

static bool	parse_axis(const char *element)
{
	if (*element == ',' || *element == '\0')
	{
		print_log_field(LOG_ERROR, ERROR_EMPTY_COMPONENT);
		return (false);
	}
	if (*element == '-')
		++element;
	if (*element == '0' && (ft_tolower(*(element + 1)) == 'x'))
	{
		print_log_field(LOG_ERROR, ERROR_INVALID_CHARACTER);
		return (false);
	}
	if (*element == '0' && ft_isdigit(*(element + 1)))
	{
		print_log_field(LOG_ERROR, ERROR_LEADING_ZERO);
		return (false);
	}
	if (*element == '.')
		++element;
	if (!ft_isdigit(*element))
	{
		print_log_field(LOG_ERROR, ERROR_INVALID_CHARACTER);
		return (false);
	}
	return (true);
}
