/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 00:16:11 by stanaka2          #+#    #+#             */
/*   Updated: 2026/04/05 19:28:30 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "cub3d.h"

# define FOV 66
# define MOVE_SPEED 0.05
# define PLAYER_OFFSET 0.3

enum e_hit_side
{
	X_SIDE,
	Y_SIDE,
};

struct s_hit
{
	t_ivec2			pos;
	t_dvec2			wall_dist;
	t_hit_side		side;
	const t_img		*wall_texture;
	double			perp_wall_dist;
};

struct s_wall
{
	const t_img		*texture;
	t_ivec2			texture_pixel;
	int				height;
	int				top;
	int				bottom;
	int				draw_start;
	int				draw_end;
};

void	init_player(const t_map *map, t_player *player);
void	draw_game(t_cub3d *cub3d);
t_hit	dda_algorithm(const t_cub3d *cub3d, t_dvec2 ray);
t_wall	compute_wall(const t_cub3d *cub3d, t_dvec2 ray, const t_hit *hit);
void	draw_virtical_pixels(t_cub3d *cub3d, int win_x, t_wall *wall);
void	rotate_left_player_dir(t_player *player);
void	rotate_right_player_dir(t_player *player);
void	move_forward_player_pos(const t_map *map, t_player *player);
void	move_left_player_pos(const t_map *map, t_player *player);
void	move_back_player_pos(const t_map *map, t_player *player);
void	move_right_player_pos(const t_map *map, t_player *player);

#endif
