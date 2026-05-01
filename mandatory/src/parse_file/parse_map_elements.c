/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_elements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 22:21:17 by stanaka2          #+#    #+#             */
/*   Updated: 2026/03/12 17:51:22 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	parse_map_line_elements(t_map *map, int y);
static bool	validate_map_element(t_map *map, int x, int y);
static bool	is_player_map_element(t_map *map, int x, int y);

bool	parse_map_elements(t_map *map)
{
	int	y;

	map->player_dir = '\0';
	y = 0;
	while (y < map->row_size)
	{
		if (!parse_map_line_elements(map, y))
			return (false);
		y++;
	}
	if (map->player_dir == '\0')
	{
		print_error(ERROR_MAP_NO_PLAYER);
		return (false);
	}
	return (true);
}

static bool	parse_map_line_elements(t_map *map, int y)
{
	int		x;
	bool	is_empty_line;

	x = 0;
	is_empty_line = true;
	while (x < map->col_size[y])
	{
		if (!validate_map_element(map, x, y))
			return (false);
		if (map->data[y][x] != MAP_BLANK)
			is_empty_line = false;
		if (is_player_map_element(map, x, y))
		{
			map->player_dir = map->data[y][x];
			map->player_pos = ivec2(x, y);
			map->data[y][x] = MAP_FLOOR;
		}
		x++;
	}
	if (is_empty_line == true)
	{
		print_error(ERROR_MAP_EMPTY_LINE);
		return (false);
	}
	return (true);
}

static bool	validate_map_element(t_map *map, int x, int y)
{
	const char	element = map->data[y][x];

	if (element != MAP_BLANK && !is_map_element(map, x, y))
	{
		print_error(ERROR_MAP_INVALID_CHAR);
		return (false);
	}
	if (element != MAP_WALL && is_map_element(map, x, y))
	{
		if (!is_map_element(map, x - 1, y) || !is_map_element(map, x + 1, y) \
			|| !is_map_element(map, x, y - 1) || !is_map_element(map, x, y + 1))
		{
			print_error(ERROR_MAP_NOT_CLOSED);
			return (false);
		}
	}
	if (is_player_map_element(map, x, y))
	{
		if (map->player_dir != '\0')
		{
			print_error(ERROR_MAP_MULTI_PLAYER);
			return (false);
		}
	}
	return (true);
}

static bool	is_player_map_element(t_map *map, int x, int y)
{
	char	element;

	if (y < 0 || map->row_size <= y || x < 0 || map->col_size[y] <= x)
		return (false);
	element = map->data[y][x];
	if (element == PLAYER_NORTH || element == PLAYER_SOUTH \
		|| element == PLAYER_WEST || element == PLAYER_EAST)
		return (true);
	return (false);
}
