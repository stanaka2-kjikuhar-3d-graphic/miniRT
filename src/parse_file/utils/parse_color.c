/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 16:11:18 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/06/15 06:21:24 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "ft_ctype.h"
#include "ft_stdlib.h"
#include "ft_error.h"
#include "../parse_file_private.h"

static bool	parse_color_channel(char const **element, int *color);

bool	parse_color(char const *element, int *color)
{
	enum e_color_channel	channel;

	*color = 0;
	channel = RED;
	while (channel <= BLUE)
	{
		if (!parse_color_channel(&element, color))
			return (false);
		if (((channel == RED || channel == GREEN) && *element != ',') \
			|| (channel == BLUE && *element != '\0'))
		{
			print_error(ERROR_COLOR_FORMAT);
			return (false);
		}
		++element;
		++channel;
	}
	return (true);
}

static bool	parse_color_channel(char const **element, int *color)
{
	long	value;

	if (!ft_isdigit(**element) && **element != '-')
	{
		print_error(ERROR_COLOR_FORMAT);
		return (false);
	}
	value = ft_strtol(*element, (char **)element, 10);
	if (value < 0 || 255 < value)
	{
		print_error(ERROR_COLOR_RANGE);
		return (false);
	}
	*color = (*color << 8) | (int)value;
	return (true);
}
