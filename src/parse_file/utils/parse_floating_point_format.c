/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_floating_point_format.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 17:51:21 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/12 01:47:59 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "ft_ctype.h"
#include "ft_error.h"

bool	parse_floating_point_format(const char **s)
{
	if (**s == '-' || **s == '+')
		++(*s);
	if (!(ft_isdigit(**s) \
		|| (((*s)[0] == '.') && ft_isdigit((*s)[1]))))
	{
		print_error(ERROR_NUMBER_FORMAT);
		return (false);
	}
	if (**s != '.')
	{
		if ((*s)[0] == '0' && ft_isdigit((*s)[1]))
		{
			print_error(ERROR_NUMBER_LEADING_ZERO);
			return (false);
		}
		while (ft_isdigit(**s))
			++(*s);
	}
	if (**s == '.')
		++(*s);
	while (ft_isdigit(**s))
		++(*s);
	return (true);
}
