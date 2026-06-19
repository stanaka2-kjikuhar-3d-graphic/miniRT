/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 20:32:03 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/20 03:45:47 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/X.h>

#include "mlx.h"

#include "ft_mlx.h"
#include "vector.h"
#include "view.h"
#include "drawer.h"

static t_ivec2	g_click;

int	button_press_hook(unsigned int button, int x, int y)
{
	if (button == Button1)
		g_click = ivec2(x, y);
	else if (button == Button4)
	{
		if (change_fov(1.0))
			set_draw_flag(true);
	}
	else if (button == Button5)
	{
		if (change_fov(-1.0))
			set_draw_flag(true);
	}
	return (0);
}

int	button1_motion_hook(int x, int y)
{
	(void)x;
	(void)y;
	return (0);
}
