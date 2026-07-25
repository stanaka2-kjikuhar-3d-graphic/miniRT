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
#include "ft_error.h"

#include "../parser_private.h"

static bool	parse_axis(const char *element);
static bool	check_separator(const char *element, enum e_axis axis);

bool	parse_vec3(char const *element, void *value)
{
	t_vec3 *const	vector = (t_vec3 *)value;
	float *const	v[3] = {&vector->x, &vector->y, &vector->z};
	enum e_axis		axis;

	axis = X_AXIS;
	while (axis <= Z_AXIS)
	{
		if (!parse_axis(element))
			return (false);
		*(v[axis]) = (float)ft_strtod(element, (char **)&element);
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
		print_line_error_hint(ERROR_VECTOR_FORMAT, HINT_VECTOR);
		return (false);
	}
	if (((axis == X_AXIS || axis == Y_AXIS) && *element != ',') \
		|| (axis == Z_AXIS && *element != '\0'))
	{
		print_line_error(ERROR_VECTOR_CHARACTER);
		return (false);
	}
	return (true);
}

static bool	parse_axis(const char *element)
{
	if (*element == ',' || *element == '\0')
	{
		print_line_error(ERROR_VECTOR_EMPTY);
		return (false);
	}
	if (*element == '-')
		++element;
	if (*element == '0' && (ft_tolower(*(element + 1)) == 'x'))
	{
		print_line_error(ERROR_VECTOR_CHARACTER);
		return (false);
	}
	if (*element == '0' && ft_isdigit(*(element + 1)))
	{
		print_line_error(ERROR_VECTOR_LEADING_ZERO);
		return (false);
	}
	if (*element == '.')
		++element;
	if (!ft_isdigit(*element))
	{
		print_line_error(ERROR_VECTOR_CHARACTER);
		return (false);
	}
	return (true);
}
