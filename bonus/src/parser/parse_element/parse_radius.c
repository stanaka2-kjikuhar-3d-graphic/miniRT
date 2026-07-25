/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_radius.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 23:40:45 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/26 00:46:18 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "ft_error.h"

#include "../parser_private.h"

bool	parse_radius(char const *element, void *value)
{
	float *const	radius = (float *)value;
	float			diameter;

	if (!parse_float(element, &diameter))
		return (false);
	if (diameter <= 0.0f)
	{
		print_line_error(ERROR_DIAMETER_RANGE);
		return (false);
	}
	*radius = diameter / 2.0f;
	if (*radius == 0.0f)
	{
		print_line_error(ERROR_DIAMETER_SMALL);
		return (false);
	}
	return (true);
}
