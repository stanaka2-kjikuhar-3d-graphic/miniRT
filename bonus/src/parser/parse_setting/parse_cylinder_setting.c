/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder_setting.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 20:25:01 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/24 01:17:44 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "object.h"
#include "ft_error.h"

#include "../parser_private.h"

static bool	parse_cylinder(char const **elements);

bool	parse_cylinder_setting(char const **elements)
{
	size_t	count;

	count = count_split(elements);
	if (count == 6)
		return (parse_cylinder(elements));
	else
	{
		print_error_hint(ERROR_CYLINDER_COUNT, HINT_CYLINDER);
		return (false);
	}
}

static bool	parse_cylinder(char const **elements)
{
	t_input_cylinder	input;

	if (!parse_pos(elements[1], &(input.center)) \
		|| !parse_dir(elements[2], &(input.dir)) \
		|| !parse_radius(elements[3], &(input.radius)) \
		|| !parse_half_height(elements[4], &(input.half_height)) \
		|| !parse_color(elements[5], &(input.color)))
	{
		return (false);
	}
	return (add_cylinder(&input));
}
