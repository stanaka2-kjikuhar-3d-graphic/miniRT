/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 18:16:56 by stanaka2          #+#    #+#             */
/*   Updated: 2026/04/05 19:24:41 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_player_pos(const t_map *map, t_player *player, t_dvec2 move);

void	move_forward_player_pos(const t_map *map, t_player *player)
{
	const t_dvec2	move = dvec2_scale(player->dir, MOVE_SPEED);

	move_player_pos(map, player, move);
}

void	move_left_player_pos(const t_map *map, t_player *player)
{
	const t_dvec2	dir = dvec2_rotate(player->dir, degree_to_radian(-90));
	const t_dvec2	move = dvec2_scale(dir, MOVE_SPEED);

	move_player_pos(map, player, move);
}

void	move_back_player_pos(const t_map *map, t_player *player)
{
	const t_dvec2	dir = dvec2_rotate(player->dir, degree_to_radian(180));
	const t_dvec2	move = dvec2_scale(dir, MOVE_SPEED);

	move_player_pos(map, player, move);
}

void	move_right_player_pos(const t_map *map, t_player *player)
{
	const t_dvec2	dir = dvec2_rotate(player->dir, degree_to_radian(90));
	const t_dvec2	move = dvec2_scale(dir, MOVE_SPEED);

	move_player_pos(map, player, move);
}

void	move_player_pos(const t_map *map, t_player *player, t_dvec2 move)
{
	t_dvec2	new_pos;

	new_pos = dvec2_add(player->pos, move);
	if (map->data[(int)new_pos.y][(int)player->pos.x] != MAP_FLOOR)
	{
		new_pos.y = player->pos.y;
	}
	if (map->data[(int)player->pos.y][(int)new_pos.x] != MAP_FLOOR)
	{
		new_pos.x = player->pos.x;
	}
	if (map->data[(int)new_pos.y][(int)new_pos.x] != MAP_FLOOR)
		return ;
	player->pos = new_pos;
}
