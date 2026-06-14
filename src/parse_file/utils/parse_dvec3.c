/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dvec3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 09:47:15 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/15 06:50:59 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "ft_stdlib.h"
#include "vector.h"
#include "ft_error.h"
#include "../parse_file_private.h"

bool	parse_dvec3(char const *element, t_dvec3 *vector)
{
	double *const	v[3] = {&vector->x, &vector->y, &vector->z};
	enum e_axis		axis;

	axis = X_AXIS;
	while (axis <= Z_AXIS)
	{
		if (!is_valid_floating_point_format(element))
		{
			print_error(ERROR_VECTOR_FORMAT);
			return (false);
		}
		*(v[axis]) = ft_strtod(element, (char **)&element);
		if (((axis == X_AXIS || axis == Y_AXIS) && *element != ',') \
			|| (axis == Z_AXIS && *element != '\0'))
		{
			print_error(ERROR_VECTOR_FORMAT);
			return (false);
		}
		++element;
		++axis;
	}
	return (true);
}
