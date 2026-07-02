/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient_light_setting.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 14:06:28 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/03 04:39:08 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "ft_error.h"
#include "light.h"

#include "../parser_private.h"

static bool	parse_ambient_light(char const **elements);

bool	parse_ambient_light_setting(char const **elements)
{
	size_t	count;

	count = count_split(elements);
	if (count != 3)
	{
		print_error_hint(ERROR_A_COUNT, HINT_A);
		return (false);
	}
	return (parse_ambient_light(elements));
}

static bool	parse_ambient_light(char const **elements)
{
	t_input_ambient_light	input;

	if (!parse_brightness(elements[1], &(input.brightness)) \
		|| !parse_color(elements[2], &(input.color)))
	{
		return (false);
	}
	create_ambient_light(&input);
	return (true);
}
