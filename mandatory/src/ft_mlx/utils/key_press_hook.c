/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 19:28:50 by stanaka2          #+#    #+#             */
/*   Updated: 2026/04/05 19:23:49 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press_hook(int keycode, t_cub3d *cub3d)
{
	if (keycode == XK_Escape)
		mlx_loop_end(cub3d->mlx.mlx_ptr);
	else if (keycode == XK_Left)
		rotate_left_player_dir(&(cub3d->player));
	else if (keycode == XK_Right)
		rotate_right_player_dir(&(cub3d->player));
	else if (keycode == XK_w)
		move_forward_player_pos(&(cub3d->map), &(cub3d->player));
	else if (keycode == XK_a)
		move_left_player_pos(&(cub3d->map), &(cub3d->player));
	else if (keycode == XK_s)
		move_back_player_pos(&(cub3d->map), &(cub3d->player));
	else if (keycode == XK_d)
		move_right_player_pos(&(cub3d->map), &(cub3d->player));
	return (0);
}
