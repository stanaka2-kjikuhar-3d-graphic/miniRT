/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 23:10:00 by stanaka2          #+#    #+#             */
/*   Updated: 2026/11/03 19:04:50 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "ft_math.h"
#include "ft_string.h"
#include "logger.h"

#include "config.h"
#include "viewport.h"
#include "color.h"

#include "./viewport_private.h"

static t_viewport	g_viewport;

t_viewport const	*get_viewport(void)
{
	return (&g_viewport);
}

t_viewport	*get_mutable_viewport(void)
{
	return (&g_viewport);
}

bool	init_viewport(float fov)
{
	g_viewport.buffer \
		= malloc(sizeof(t_color) * (size_t)WINDOW_WIDTH * WINDOW_HEIGHT);
	if (g_viewport.buffer == NULL)
	{
		print_log_errno(LOG_ERROR);
		return (false);
	}
	g_viewport.sample_count = 0;
	if (!init_resolution(&(g_viewport.resolution)))
		return (false);
	g_viewport.aspect_ratio = (float)((double)WINDOW_WIDTH / WINDOW_HEIGHT);
	g_viewport.half_size.width = tanf((float)(fov * DEG_TO_RAD * 0.5f));
	g_viewport.half_size.height \
		= g_viewport.half_size.width / g_viewport.aspect_ratio;
	return (true);
}

void	cleanup_viewport(void)
{
	enum e_resolution_level	level;

	free(g_viewport.buffer);
	level = 0;
	while (level < RESOLUTION_COUNT)
	{
		free(g_viewport.resolution.render_pixel[level]);
		++level;
	}
	ft_bzero(&g_viewport, sizeof(t_viewport));
}
