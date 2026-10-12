/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 23:10:00 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/04 22:00:27 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "ft_math.h"

#include "config.h"
#include "vector.h"
#include "viewport.h"

static t_viewport	g_viewport;

t_viewport const	*get_viewport(void)
{
	return (&g_viewport);
}

void	set_viewport(float fov)
{
	g_viewport.pixel_size.width = WINDOW_WIDTH;
	g_viewport.pixel_size.height = WINDOW_HEIGHT;
	g_viewport.pixel_count = WINDOW_WIDTH * WINDOW_HEIGHT;
	g_viewport.pixel_half_size.width = WINDOW_WIDTH / 2.0;
	g_viewport.pixel_half_size.height = WINDOW_HEIGHT / 2.0;
	g_viewport.aspect_ratio = (float)WINDOW_WIDTH / WINDOW_HEIGHT;
	g_viewport.world_half_size.width = tanf(fov * (float)DEG_TO_RAD * 0.5f);
	g_viewport.world_half_size.height \
		= g_viewport.world_half_size.width / g_viewport.aspect_ratio;
}

void	change_viewport(float fov)
{
	g_viewport.world_half_size.width = tanf(fov * (float)DEG_TO_RAD * 0.5f);
	g_viewport.world_half_size.height \
		= g_viewport.world_half_size.width / g_viewport.aspect_ratio;
}
