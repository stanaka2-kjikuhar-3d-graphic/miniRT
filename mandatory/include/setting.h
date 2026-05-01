/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 15:54:17 by stanaka2          #+#    #+#             */
/*   Updated: 2026/03/11 12:03:29 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTING_H
# define SETTING_H

# include "type.h"

# define SETTING_COUNT 6

struct s_setting
{
	int		flags;
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	t_color	floor_color;
	t_color	ceiling_color;
};

enum e_setting_flag
{
	FLAG_NORTH = (1 << 0),
	FLAG_SOUTH = (1 << 1),
	FLAG_WEST = (1 << 2),
	FLAG_EAST = (1 << 3),
	FLAG_FLOOR_COLOR = (1 << 4),
	FLAG_CEILING_COLOR = (1 << 5),
};

bool	is_setting_incomplete(t_setting *setting);
bool	set_north_texture(t_setting *setting, char *data);
bool	set_south_texture(t_setting *setting, char *data);
bool	set_west_texture(t_setting *setting, char *data);
bool	set_east_texture(t_setting *setting, char *data);
bool	set_floor_color(t_setting *setting, char *data);
bool	set_ceiling_color(t_setting *setting, char *data);

#endif
