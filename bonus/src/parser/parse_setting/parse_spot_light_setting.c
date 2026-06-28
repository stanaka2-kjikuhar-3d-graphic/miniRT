/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_spot_light_setting.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 04:26:53 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/29 06:27:16 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stddef.h>
#include <stdbool.h>

#include "ft_error.h"
#include "vector.h"
#include "light.h"

#include "../parser_private.h"

static bool	parse_spot_light(char const **elements);

bool	parse_spot_light_setting(char const **elements)
{
	size_t	count;

	count = count_split(elements);
	if (count == 6)
	{
		print_error_hint(ERROR_L_COUNT, HINT_L);
		return (false);
	}
	return (parse_spot_light(elements));
}

static bool	parse_spot_light(char const **elements)
{
	t_input_spot_light	input;

	if (!parse_pos(elements[1], &(input.pos)) \
		|| !parse_brightness(elements[2], &(input.brightness)) \
		|| !parse_color(elements[3], &(input.color))
		|| !parse_dir(elements[4], &(input.dir)) \
		|| !parse_angle(elements[5], &(input.outer_angle)))
	{
		return (false);
	}
	if (!create_spot_light(&input))
		return (false);
	return (true);
}
