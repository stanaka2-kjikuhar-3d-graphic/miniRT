/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 16:00:46 by stanaka2          #+#    #+#             */
/*   Updated: 2026/03/12 17:46:14 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "type.h"

# define MAP_BLANK ' '
# define MAP_FLOOR '0'
# define MAP_WALL '1'
# define PLAYER_NORTH 'N'
# define PLAYER_SOUTH 'S'
# define PLAYER_WEST 'W'
# define PLAYER_EAST 'E'

struct s_map
{
	char	**data;
	int		row_size;
	int		*col_size;
	char	player_dir;
	t_ivec2	player_pos;
};

#endif
