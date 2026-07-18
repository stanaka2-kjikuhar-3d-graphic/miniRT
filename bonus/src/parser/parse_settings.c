/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_settings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 22:43:09 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/14 14:12:03 by stanaka2         ###   ########.fr       */
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
	return (true);
}

static bool	parse_setting(char const **elements)
{
	if (is_setting_id("A", elements[0]))
		return (parse_ambient_light_setting(elements));
	else if (is_setting_id("L", elements[0]))
		return (parse_point_light_setting(elements));
	else if (is_setting_id("C", elements[0]))
		return (parse_camera_setting(elements));
	else if (is_setting_id("sl", elements[0]))
		return (parse_spot_light_setting(elements));
	else if (is_setting_id("sp", elements[0]))
		return (parse_sphere_setting(elements));
	else if (is_setting_id("pl", elements[0]))
		return (parse_plane_setting(elements));
	else if (is_setting_id("cy", elements[0]))
		return (parse_cylinder_setting(elements));
	else
	{
		print_error(ERROR_ID_UNKNOWN);
		return (false);
	}
}
