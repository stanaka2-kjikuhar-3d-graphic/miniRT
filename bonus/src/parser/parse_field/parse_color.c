/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 16:11:18 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/07/26 00:45:19 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdbool.h>

#include "ft_ctype.h"
#include "ft_stdlib.h"

#include "ft_error.h"
#include "color.h"

#include "../parser_private.h"

static bool	check_separator(const char *element, enum e_color_channel i);
static bool	parse_color_channel(char const **element, float *channel);

bool	parse_color(char const *element, void *value)
{
	t_color *const			color = (t_color *)value;
	float *const			channels[] = {\
								&(color->r), &(color->g), &(color->b)};
	enum e_color_channel	i;

	i = RED;
	while (i <= BLUE)
	{
		if (!parse_color_channel(&element, channels[i]))
			return (false);
		if (!check_separator(element, i))
			return (false);
		++element;
		++i;
	}
	return (true);
}

static bool	check_separator(const char *element, enum e_color_channel i)
{
	if (((i == RED || i == GREEN) && *element == '\0') \
		|| (i == BLUE && *element == ','))
	{
		print_line_error(ERROR_COLOR_FORMAT, HINT_COLOR);
		return (false);
	}
	if (((i == RED || i == GREEN) && *element != ',') \
		|| (i == BLUE && *element != '\0'))
	{
		print_line_error(ERROR_COLOR_NON_DIGIT, NULL);
		return (false);
	}
	return (true);
}

static bool	parse_color_channel(char const **element, float *channel)
{
	long	value;

	if (**element == ',' || **element == '\0')
	{
		print_line_error(ERROR_COLOR_EMPTY, NULL);
		return (false);
	}
	if (!ft_isdigit(**element))
	{
		print_line_error(ERROR_COLOR_NON_DIGIT, NULL);
		return (false);
	}
	if (**element == '0' && ft_isdigit(*(*element + 1)))
	{
		print_line_error(ERROR_COLOR_LEADING_ZERO, NULL);
		return (false);
	}
	value = ft_strtol(*element, (char **)element, 10);
	if (0xFF < value)
	{
		print_line_error(ERROR_COLOR_RANGE, NULL);
		return (false);
	}
	*channel = decode_color((uint8_t)value);
	return (true);
}
