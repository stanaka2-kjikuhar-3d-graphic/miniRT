/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 18:25:33 by stanaka2          #+#    #+#             */
/*   Updated: 2026/04/04 17:15:16 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_mlx_hooks(t_cub3d *cub3d)
{
	mlx_expose_hook(cub3d->mlx.win_ptr, expose_hook, cub3d);
	mlx_hook(cub3d->mlx.win_ptr, ClientMessage, NoEventMask, \
		mlx_loop_end, cub3d->mlx.mlx_ptr);
	mlx_hook(cub3d->mlx.win_ptr, KeyRelease, KeyReleaseMask, \
		key_release_hook, cub3d);
	mlx_hook(cub3d->mlx.win_ptr, KeyPress, KeyPressMask, \
		key_press_hook, cub3d);
	mlx_hook(cub3d->mlx.win_ptr, ButtonPress, ButtonPressMask, \
		button_press_hook, cub3d);
	mlx_hook(cub3d->mlx.win_ptr, MotionNotify, Button1MotionMask, \
		button1_motion_hook, cub3d);
	mlx_loop_hook(cub3d->mlx.mlx_ptr, loop_hook, cub3d);
	mlx_loop(cub3d->mlx.mlx_ptr);
}
