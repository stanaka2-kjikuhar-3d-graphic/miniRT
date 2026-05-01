/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_element.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 22:19:02 by stanaka2          #+#    #+#             */
/*   Updated: 2026/03/11 15:34:35 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_map_element(t_map *map, int x, int y)
{
	char	element;

	if (y < 0 || map->row_size <= y || x < 0 || map->col_size[y] <= x)
		return (false);
	element = map->data[y][x];
	if (element == MAP_FLOOR || element == MAP_WALL)
		return (true);
	if (element == PLAYER_NORTH || element == PLAYER_SOUTH \
		|| element == PLAYER_WEST || element == PLAYER_EAST)
		return (true);
	return (false);
}
