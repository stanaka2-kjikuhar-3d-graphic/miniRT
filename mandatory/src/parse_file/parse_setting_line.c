/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_setting_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 12:34:48 by stanaka2          #+#    #+#             */
/*   Updated: 2026/03/15 23:28:14 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	assign_setting(t_setting *setting, char *identifier, char *value);

bool	parse_setting_line(t_setting *setting, char *line)
{
	char				**data;

	data = ft_split(line, ' ');
	if (data == NULL || data[0] == NULL || data[1] == NULL || data[2] != NULL)
	{
		if (data == NULL)
			print_error(strerror(errno));
		else if (data[0] == NULL)
			print_error(ERROR_SETTING_ONLY_SPACE);
		else if (data[1] == NULL)
			print_error(ERROR_SETTING_MISSING_VALUE);
		else
			print_error(ERROR_SETTING_EXTRA_VALUE);
		free_splitted(data);
		return (false);
	}
	if (!assign_setting(setting, data[0], data[1]))
	{
		free_splitted(data);
		return (false);
	}
	free_splitted(data);
	return (true);
}

static bool	assign_setting(t_setting *setting, char *identifier, char *value)
{
	t_setting_setter	setter;

	if (ft_strcmp("NO", identifier) == 0)
		setter = set_north_texture;
	else if (ft_strcmp("SO", identifier) == 0)
		setter = set_south_texture;
	else if (ft_strcmp("WE", identifier) == 0)
		setter = set_west_texture;
	else if (ft_strcmp("EA", identifier) == 0)
		setter = set_east_texture;
	else if (ft_strcmp("F", identifier) == 0)
		setter = set_floor_color;
	else if (ft_strcmp("C", identifier) == 0)
		setter = set_ceiling_color;
	else
	{
		print_error(ERROR_SETTING_UNKNOWN_ID);
		return (false);
	}
	if (!setter(setting, value))
		return (false);
	return (true);
}
