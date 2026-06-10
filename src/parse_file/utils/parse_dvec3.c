/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dvec3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 09:47:15 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/10 19:42:01 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "ft_stdlib.h"
#include "vector.h"
#include "ft_error.h"
#include "../parse_file_private.h"

bool	parse_dvec3(char const *s, t_dvec3 *vector)
{
	enum e_axis	axis;

	axis = X_AXIS;
	while (axis <= Z_AXIS)
	{
		if (axis == X_AXIS)
			vector->x = ft_atof(s);
		else if (axis == Y_AXIS)
			vector->y = ft_atof(s);
		else if (axis == Z_AXIS)
			vector->z = ft_atof(s);
		if (!parse_floating_point_format(&s))
			return (false);
		if (((axis == X_AXIS || axis == Y_AXIS) && *s != ',') \
			|| (axis == Z_AXIS && *s != '\0'))
		{
			print_error("");
			return (false);
		}
		++s;
		++axis;
	}
	return (true);
}
