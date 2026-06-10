/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_settings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 22:43:09 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/10 20:00:19 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include <errno.h>

#include "ft_lst.h"
#include "ft_string.h"
#include "ft_error.h"
#include "./parse_file_private.h"

static bool	parse_setting(char const *setting);

bool	parse_settings(t_list **line_list)
{
	char	*setting;
	char	**elements;

	while (*line_list != NULL)
	{
		setting = ft_lst_pop_front(line_list);
		elements = ft_split(setting, ' ');
		free(setting);
		if (elements == NULL)
		{
			print_error(strerror(errno));
			return (false);
		}
		if (!parse_setting(setting))
		{
			free_splitted(elements);
			return (false);
		}
		free_splitted(elements);
	}
	return (true);
}

static bool	parse_setting(char const **elements)
{
	return (true);
	// if (is_identifier("A", elements[0]))
	// 	return (parse_ambient_lighting_setting(elements));
	// else if (is_identifier("L", elements[0]))
	// 	return (parse_light_setting(elements));
	// else if (is_identifier("C", elements[0]))
	// 	return (parse_camera_setting(elements));
	// else if (is_identifier("sp", elements[0]))
	// 	return (parse_sphere_setting(elements));
	// else if (is_identifier("pl", elements[0]))
	// 	return (parse_plane_setting(elements));
	// else if (is_identifier("cy", elements[0]))
	// 	return (parse_cylinder_setting(elements));
	// else
	// 	return (false);
}
