/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 16:11:18 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/06/19 12:56:35 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "ft_ctype.h"
#include "ft_stdlib.h"
#include "ft_error.h"
#include "color.h"
#include "../parse_file_private.h"

static bool	parse_color_channel(char const **element, double *channel);

bool	parse_color(char const *element, t_color *color)
{
	double *const			channel[] = {&(color->r), &(color->g), &(color->b)};
	enum e_color_channel	i;

	i = RED;
	while (i <= BLUE)
	{
		if (!parse_color_channel(&element, channel[i]))
			return (false);
		if (((i == RED || i == GREEN) && *element == '\0') \
			|| (i == BLUE && *element == ','))
		{
			print_error_hint(ERROR_COLOR_FORMAT, HINT_COLOR);
			return (false);
		}
		if (((i == RED || i == GREEN) && *element != ',') \
			|| (i == BLUE && *element != '\0'))
		{
			print_error(ERROR_COLOR_NON_DIGIT);
			return (false);
		}
		++element;
		++i;
	}
	return (true);
}

static bool	parse_color_channel(char const **element, double *channel)
{
	long	value;

	if (**element == ',' || **element == '\0')
	{
		print_error(ERROR_COLOR_EMPTY);
		return (false);
	}
	if (!ft_isdigit(**element))
	{
		print_error(ERROR_COLOR_NON_DIGIT);
		return (false);
	}
	if (**element == '0' && ft_isdigit(*(*element + 1)))
	{
		print_error(ERROR_COLOR_LEADING_ZERO);
		return (false);
	}
	value = ft_strtol(*element, (char **)element, 10);
	if (0xFF < value)
	{
		print_error(ERROR_COLOR_RANGE);
		return (false);
	}
	*channel = (double)value / 0xFF;
	return (true);
}
