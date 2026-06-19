/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 23:10:00 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/19 20:54:25 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "ft_mlx.h"
#include "vector.h"
#include "view.h"

static t_viewport	g_viewport;

t_viewport const	*get_viewport(void)
{
	return (&g_viewport);
}

void	set_viewport(double horizontal_fov)
{
	g_viewport.pixel.width = WINDOW_WIDTH;
	g_viewport.pixel.height = WINDOW_HEIGHT;
	g_viewport.aspect_ratio = (double)WINDOW_WIDTH / WINDOW_HEIGHT;
	g_viewport.horizontal_fov = horizontal_fov;
	g_viewport.vertical_fov \
		= 2 * atan(tan(horizontal_fov / 2) / g_viewport.aspect_ratio);
	g_viewport.half_width = tan(horizontal_fov * 0.5);
	g_viewport.half_height = g_viewport.half_width / g_viewport.aspect_ratio;
}
