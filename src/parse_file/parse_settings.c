/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_settings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 22:43:09 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/10 00:23:29 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

#include "ft_lst.h"
#include "./parse_file_private.h"

static bool	parse_setting(char const *setting);

bool	parse_settings(t_list **line_list)
{
	char	*setting;

	while (*line_list != NULL)
	{
		setting = ft_lst_pop_front(line_list);
		if (!parse_setting(setting))
		{
			free(setting);
			return (false);
		}
		free(setting);
	}
	return (true);
}

static bool	parse_setting(char const *setting)
{
	(void)setting;
	return (true);
	// if (is_identifier("A", setting))
	// 	return (parse_ambient_lighting_setting(setting));
	// else if (is_identifier("L", setting))
	// 	return (parse_light_setting(setting));
	// else if (is_identifier("C", setting))
	// 	return (parse_camera_setting(setting));
	// else if (is_identifier("sp", setting))
	// 	return (parse_sphere_setting(setting));
	// else if (is_identifier("pl", setting))
	// 	return (parse_plane_setting(setting));
	// else if (is_identifier("cy", setting))
	// 	return (parse_cylinder_setting(setting));
	// else
	// 	return (false);
}
