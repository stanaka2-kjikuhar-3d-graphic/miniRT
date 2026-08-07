/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 23:10:00 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/07 23:20:15 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>

#include "ft_math.h"

#include "config.h"
#include "vector.h"
#include "viewport.h"

static t_viewport	g_viewport;

t_viewport const	*get_viewport(void)
{
	return (&g_viewport);
}

void	set_viewport(t_input_viewport const *input)
{
	g_viewport.pixel_size.width = WINDOW_WIDTH;
	g_viewport.pixel_size.height = WINDOW_HEIGHT;
	g_viewport.pixel_count = WINDOW_WIDTH * WINDOW_HEIGHT;
	g_viewport.pixel_half_size.width = WINDOW_WIDTH / 2.0;
	g_viewport.pixel_half_size.height = WINDOW_HEIGHT / 2.0;
	g_viewport.aspect_ratio = (float)WINDOW_WIDTH / WINDOW_HEIGHT;
	g_viewport.fov = input->fov;
	g_viewport.world_half_size.width \
		= tanf(g_viewport.fov * (float)DEG_TO_RAD * 0.5f);
	g_viewport.world_half_size.height \
		= g_viewport.world_half_size.width / g_viewport.aspect_ratio;
}

bool	change_viewport_fov(float degree)
{
	if (g_viewport.fov + degree <= EPSILON \
		|| 180.0 - EPSILON <= g_viewport.fov + degree)
	{
		return (false);
	}
	g_viewport.fov = g_viewport.fov + degree;
	g_viewport.world_half_size.width \
		= tanf(g_viewport.fov * (float)DEG_TO_RAD * 0.5f);
	g_viewport.world_half_size.height \
		= g_viewport.world_half_size.width / g_viewport.aspect_ratio;
	return (true);
}
