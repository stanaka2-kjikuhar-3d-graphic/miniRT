/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 23:10:00 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/20 02:34:32 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "config.h"
#include "vector.h"
#include "view.h"

static t_viewport	g_viewport;

t_viewport const	*get_viewport(void)
{
	return (&g_viewport);
}

void	set_viewport(double horizontal_fov)
{
	g_viewport.pixel_size.width = WINDOW_WIDTH;
	g_viewport.pixel_size.height = WINDOW_HEIGHT;
	g_viewport.pixel_half_size.width = WINDOW_WIDTH / 2.0;
	g_viewport.pixel_half_size.height = WINDOW_HEIGHT / 2.0;
	g_viewport.aspect_ratio = (double)WINDOW_WIDTH / WINDOW_HEIGHT;
	g_viewport.fov.horizontal = horizontal_fov;
	g_viewport.fov.vertical \
		= 2 * atan(tan(horizontal_fov / 2) / g_viewport.aspect_ratio);
	g_viewport.world_half_size.width = tan(horizontal_fov * 0.5);
	g_viewport.world_half_size.height \
		= g_viewport.world_half_size.width / g_viewport.aspect_ratio;
}
