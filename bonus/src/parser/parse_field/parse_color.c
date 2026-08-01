/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 16:11:18 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/07/29 00:21:06 by stanaka2         ###   ########.fr       */
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
static bool	parse_color_channel(char const **element, unsigned int *rgb);

bool	parse_color(char const *element, void *value)
{
	t_color *const			color = (t_color *)value;
	unsigned int			rgb;
	enum e_color_channel	i;

	rgb = 0;
	i = RED;
	while (i <= BLUE)
	{
		if (!parse_color_channel(&element, &rgb))
			return (false);
		if (!check_separator(element, i))
			return (false);
		++element;
		++i;
	}
	*color = decode_color(rgb);
	return (true);
}

static bool	parse_color_channel(char const **element, unsigned int *rgb)
{
	long	channel;

	if (**element == ',' || **element == '\0')
	{
		print_field_error(ERROR_EMPTY_CHANNEL, NULL);
		return (false);
	}
	if (!ft_isdigit(**element))
	{
		print_field_error(ERROR_ONLY_DIGITS, NULL);
		return (false);
	}
	if (**element == '0' && ft_isdigit(*(*element + 1)))
	{
		print_field_error(ERROR_LEADING_ZERO, NULL);
		return (false);
	}
	channel = ft_strtol(*element, (char **)element, 10);
	if (0xFF < channel)
	{
		print_field_error(ERROR_OUT_OF_RANGE, HINT_COLOR_RANGE);
		return (false);
	}
	*rgb = (*rgb << 8) | (unsigned int)channel;
	return (true);
}

static bool	check_separator(const char *element, enum e_color_channel i)
{
	if (((i == RED || i == GREEN) && *element == '\0') \
		|| (i == BLUE && *element == ','))
	{
		print_field_error(ERROR_INVALID_FORMAT, HINT_COLOR);
		return (false);
	}
	if (((i == RED || i == GREEN) && *element != ',') \
		|| (i == BLUE && *element != '\0'))
	{
		print_field_error(ERROR_ONLY_DIGITS, NULL);
		return (false);
	}
	return (true);
}
