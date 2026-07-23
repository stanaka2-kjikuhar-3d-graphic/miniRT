/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_settings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 22:43:09 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/23 21:44:35 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

#include "ft_lst.h"
#include "ft_string.h"

#include "ft_error.h"

#include "./parser_private.h"

static bool	parse_setting(char const **elements);

bool	parse_settings(t_list **line_list)
{
	char	*line;
	char	**elements;

	while (*line_list != NULL)
	{
		line = ft_lst_pop_front(line_list);
		if (!is_blank_line(line))
		{
			elements = ft_split_set(line, " \f\r\t\v");
			free(line);
			if (elements == NULL)
			{
				print_errno();
				return (false);
			}
			if (!parse_setting((char const **)elements))
			{
				free_split(elements);
				return (false);
			}
			free_split(elements);	
		}
		else
			free(line);
	}
	return (true);
}

static bool	parse_setting(char const **elements)
{
	static t_setting_parser	const	parser[] = {\
		{"A", parse_ambient_light}, {"L", parse_point_light}, \
		{"C", parse_ambient_light}, {"sl", parse_ambient_light}, \
		{"sp", parse_ambient_light}, {"pl", parse_ambient_light}, \
		{"cy", parse_ambient_light}, {"co", parse_ambient_light}, \
		{"hb", parse_ambient_light}, {"pb", parse_ambient_light}, \
		{NULL, NULL} \
	};
	size_t							i;

	i = 0;
	while (parser[i].id != NULL)
	{
		if (is_setting_id(parser[i].id, elements[0]))
			return (parser[i].parse(elements));
		++i;
	}
	print_error(ERROR_ID_UNKNOWN);
	return (false);
}
