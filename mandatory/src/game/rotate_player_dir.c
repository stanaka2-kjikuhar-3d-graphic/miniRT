/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player_dir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 18:16:53 by stanaka2          #+#    #+#             */
/*   Updated: 2026/04/05 19:21:59 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_left_player_dir(t_player *player)
{
	player->dir = dvec2_rotate(player->dir, degree_to_radian(-1.0));
	player->plane = dvec2_rotate(player->plane, degree_to_radian(-1.0));
}

void	rotate_right_player_dir(t_player *player)
{
	player->dir = dvec2_rotate(player->dir, degree_to_radian(1.0));
	player->plane = dvec2_rotate(player->plane, degree_to_radian(1.0));
}
