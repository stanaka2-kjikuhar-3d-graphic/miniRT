/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 23:56:54 by stanaka2          #+#    #+#             */
/*   Updated: 2026/03/11 14:02:42 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	set_north_texture(t_setting *setting, char *data)
{
	if (setting->flags & FLAG_NORTH)
	{
		print_error(ERROR_SETTING_DUPLICATE);
		return (false);
	}
	setting->flags |= FLAG_NORTH;
	setting->north_texture = ft_strdup(data);
	if (setting->north_texture == NULL)
	{
		print_error(strerror(errno));
		return (false);
	}
	return (true);
}

bool	set_south_texture(t_setting *setting, char *data)
{
	if (setting->flags & FLAG_SOUTH)
	{
		print_error(ERROR_SETTING_DUPLICATE);
		return (false);
	}
	setting->flags |= FLAG_SOUTH;
	setting->south_texture = ft_strdup(data);
	if (setting->south_texture == NULL)
	{
		print_error(strerror(errno));
		return (false);
	}
	return (true);
}

bool	set_west_texture(t_setting *setting, char *data)
{
	if (setting->flags & FLAG_WEST)
	{
		print_error(ERROR_SETTING_DUPLICATE);
		return (false);
	}
	setting->flags |= FLAG_WEST;
	setting->west_texture = ft_strdup(data);
	if (setting->west_texture == NULL)
	{
		print_error(strerror(errno));
		return (false);
	}
	return (true);
}

bool	set_east_texture(t_setting *setting, char *data)
{
	if (setting->flags & FLAG_EAST)
	{
		print_error(ERROR_SETTING_DUPLICATE);
		return (false);
	}
	setting->flags |= FLAG_EAST;
	setting->east_texture = ft_strdup(data);
	if (setting->east_texture == NULL)
	{
		print_error(strerror(errno));
		return (false);
	}
	return (true);
}
