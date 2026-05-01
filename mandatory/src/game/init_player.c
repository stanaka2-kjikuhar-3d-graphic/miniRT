/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 15:36:12 by stanaka2          #+#    #+#             */
/*   Updated: 2026/03/24 10:40:13 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// FOV = 2 * atan(plane_length / dir_length)
void	init_player(const t_map *map, t_player *player)
{
	double	plane_length;

	player->pos = dvec2(map->player_pos.x + 0.5, map->player_pos.y + 0.5);
	player->fov = FOV;
	plane_length = tan(degree_to_radian(player->fov / 2));
	if (map->player_dir == PLAYER_NORTH)
	{
		player->dir = dvec2(0, -1);
		player->plane = dvec2(plane_length, 0);
	}
	else if (map->player_dir == PLAYER_SOUTH)
	{
		player->dir = dvec2(0, 1);
		player->plane = dvec2(-plane_length, 0);
	}
	else if (map->player_dir == PLAYER_WEST)
	{
		player->dir = dvec2(-1, 0);
		player->plane = dvec2(0, plane_length);
	}
	else if (map->player_dir == PLAYER_EAST)
	{
		player->dir = dvec2(1, 0);
		player->plane = dvec2(0, -plane_length);
	}
}
