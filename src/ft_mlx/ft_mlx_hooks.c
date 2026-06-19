/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 16:31:08 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/20 04:56:00 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <X11/X.h>

#include "mlx.h"

#include "ft_mlx.h"

#include "./ft_mlx_private.h"

void	ft_mlx_hooks(void)
{
	mlx_expose_hook(get_win_ptr(), draw_hook, NULL);
	mlx_loop_hook(get_mlx_ptr(), draw_hook, NULL);
	mlx_hook(get_win_ptr(), ClientMessage, NoEventMask, \
								mlx_loop_end, get_mlx_ptr());
	mlx_hook(get_win_ptr(), KeyPress, KeyPressMask, \
								key_press_hook, NULL);
	mlx_hook(get_win_ptr(), KeyRelease, KeyReleaseMask, \
								key_release_hook, NULL);
	mlx_hook(get_win_ptr(), ButtonPress, ButtonPressMask, \
								button_press_hook, NULL);
	mlx_hook(get_win_ptr(), ButtonRelease, ButtonReleaseMask, \
								button_release_hook, NULL);
	mlx_hook(get_win_ptr(), MotionNotify, Button1MotionMask, \
								button1_motion_hook, NULL);
}
