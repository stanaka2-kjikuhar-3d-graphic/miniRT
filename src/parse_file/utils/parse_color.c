/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 16:11:18 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/06/10 19:42:07 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "ft_ctype.h"
#include "ft_stdlib.h"
#include "ft_error.h"
#include "../parse_file_private.h"

static bool	parse_color_channel(char const **s);

bool	parse_color(char const *s, int *color)
{
	enum e_color_channel	color_channel;

	*color = 0;
	color_channel = RED;
	while (color_channel <= BLUE)
	{
		*color = (*color << 8) | ft_atoi(s);
		if (!parse_color_channel(&s))
			return (false);
		if (((color_channel == RED || color_channel == GREEN) && *s != ',') \
			|| (color_channel == BLUE && *s != '\0'))
		{
			print_error(ERROR_COLOR_FORMAT);
			return (false);
		}
		++s;
		++color_channel;
	}
	return (true);
}

static bool	parse_color_channel(char const **s)
{
	int	value;

	if (!ft_isdigit((*s)[0]))
	{
		print_error(ERROR_COLOR_FORMAT);
		return (false);
	}
	if ((*s)[0] == '0' && ft_isdigit((*s)[1]))
	{
		print_error(ERROR_COLOR_LEADING_ZERO);
		return (false);
	}
	value = 0;
	while (ft_isdigit(**s))
	{
		value = value * 10 + (**s - '0');
		if (value > 255)
		{
			print_error(ERROR_COLOR_RANGE);
			return (false);
		}
		++(*s);
	}
	return (true);
}
