/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 16:50:32 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/20 14:00:09 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h>

#include "mlx.h"

#include "ft_mlx.h"
#include "view.h"
#include "drawer.h"

int	key_press_hook(int keycode, void *param)
{
	(void)param;
	if (keycode == XK_Escape)
		mlx_loop_end(get_mlx_ptr());
	if (keycode == XK_w)
	{
		change_camera_pos(dvec3_add(get_camera()->pos, get_camera()->dir));
		set_draw_flag(true);
	}
	else if (keycode == XK_s)
	{
		change_camera_pos(dvec3_add(get_camera()->pos, \
						dvec3_scale(-1, get_camera()->dir)));
		set_draw_flag(true);
	}
	else if (keycode == XK_Right || keycode == XK_d)
	{
		change_camera_pos(dvec3_add(get_camera()->pos, get_camera()->right));
		set_draw_flag(true);
	}
	else if (keycode == XK_Left || keycode == XK_a)
	{
		change_camera_pos(dvec3_add(get_camera()->pos, \
						dvec3_scale(-1, get_camera()->right)));
		set_draw_flag(true);
	}
	else if (keycode == XK_Up)
	{
		change_camera_pos(dvec3_add(get_camera()->pos, get_camera()->up));
		set_draw_flag(true);
	}
	else if (keycode == XK_Down)
	{
		change_camera_pos(dvec3_add(get_camera()->pos, \
						dvec3_scale(-1, get_camera()->up)));
		set_draw_flag(true);
	}

	return (0);
}
