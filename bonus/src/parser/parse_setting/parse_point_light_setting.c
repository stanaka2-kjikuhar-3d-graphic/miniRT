/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_point_light_setting.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 20:02:37 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/03 04:39:28 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "ft_error.h"
#include "light.h"

#include "../parser_private.h"

static bool	parse_point_light(char const **elements);

bool	parse_point_light_setting(char const **elements)
{
	size_t	count;

	count = count_split(elements);
	if (count != 4)
	{
		print_error_hint(ERROR_L_COUNT, HINT_L);
		return (false);
	}
	return (parse_point_light(elements));
}

static bool	parse_point_light(char const **elements)
{
	t_input_point_light	input;

	if (!parse_coordinate(elements[1], &(input.pos)) \
		|| !parse_brightness(elements[2], &(input.brightness)) \
		|| !parse_color(elements[3], &(input.color)))
	{
		return (false);
	}
	if (!create_point_light(&input))
		return (false);
	return (true);
}
