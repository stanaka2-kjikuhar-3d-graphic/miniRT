/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 20:32:03 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/23 23:56:03 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/X.h>

#include "mlx.h"

#include "config.h"
#include "ft_mlx.h"
#include "vector.h"
#include "camera.h"
#include "viewport.h"
#include "renderer.h"

static t_ivec2	g_click;
static bool		g_change_angle;

int	button_press_hook(unsigned int button, int x, int y)
{
	if (button == Button1)
	{
		g_click = ivec2(x, y);
		g_change_angle = true;
	}
	else if (button == Button4)
	{
		if (change_viewport_fov(1.0))
			set_render_flag(true);
	}
	else if (button == Button5)
	{
		if (change_viewport_fov(-1.0))
			set_render_flag(true);
	}
	return (0);
}

int	button_release_hook(unsigned int button, int x, int y)
{
	(void)x;
	(void)y;
	if (button == Button1)
	{
		g_change_angle = false;
	}
	return (0);
}

int	button1_motion_hook(int x, int y)
{
	t_ivec2	delta;

	if (!g_change_angle)
		return (0);
	delta.x = (x - g_click.x) / PIXEL_PER_ROTATE;
	delta.y = (y - g_click.y) / PIXEL_PER_ROTATE;
	if (delta.x != 0)
	{
		rotate_camera_yaw((float)delta.x);
		g_click.x = x;
		set_render_flag(true);
	}
	if (delta.y != 0)
	{
		rotate_camera_pitch((float)-delta.y);
		g_click.y = y;
		set_render_flag(true);
	}
	return (0);
}
