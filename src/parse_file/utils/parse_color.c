/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 16:11:18 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/06/11 23:34:58 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "ft_ctype.h"
#include "ft_stdlib.h"
#include "ft_error.h"
#include "../parse_file_private.h"

static bool	parse_color_channel(char const **element);

bool	parse_color(char const *element, int *color)
{
	enum e_color_channel	channel;

	*color = 0;
	channel = RED;
	while (channel <= BLUE)
	{
		*color = (*color << 8) | ft_atoi(element);
		if (!parse_color_channel(&element))
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

static bool	parse_color_channel(char const **element)
{
	int	value;

	if (!ft_isdigit((*element)[0]))
	{
		print_error(ERROR_COLOR_FORMAT);
		return (false);
	}
	if ((*element)[0] == '0' && ft_isdigit((*element)[1]))
	{
		print_error(ERROR_COLOR_LEADING_ZERO);
		return (false);
	}
	value = 0;
	while (ft_isdigit(**element))
	{
		value = value * 10 + (**element - '0');
		if (value > 255)
		{
			print_error(ERROR_COLOR_RANGE);
			return (false);
		}
		++(*element);
	}
	return (true);
}
