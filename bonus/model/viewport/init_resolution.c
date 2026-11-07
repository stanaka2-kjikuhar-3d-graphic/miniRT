/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_resolution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 09:29:23 by stanaka2          #+#    #+#             */
/*   Updated: 2026/11/07 18:32:11 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "ft_string.h"

#include "vector.h"
#include "logger.h"
#include "config.h"
#include "viewport.h"

static void						set_resolution_scale(t_resolution *resolution);
static bool						allocate_render_pixel(t_resolution *resolution);
static void						set_render_pixel(t_resolution *resolution);
static enum e_resolution_level	get_pixel_resolution_level(\
								t_resolution const *resolution, t_ivec2 pixel);

bool	init_resolution(t_resolution *resolution)
{
	resolution->level = 0;
	resolution->interpolation = NEAREST_INTERPOLATION;
	set_resolution_scale(resolution);
	if (!allocate_render_pixel(resolution))
		return (false);
	set_render_pixel(resolution);
	return (true);
}

static void	set_resolution_scale(t_resolution *resolution)
{
	enum e_resolution_level	level;
	uint8_t					scale;

	level = FULL_RESOLUTION;
	scale = 1;
	while (true)
	{
		resolution->scale[level] = scale;
		scale *= 2;
		if (level == 0)
			break ;
		--level;
	}
}

static bool	allocate_render_pixel(t_resolution *resolution)
{
	enum e_resolution_level	level;
	size_t					count;
	size_t					total_count;

	level = 0;
	total_count = 0;
	while (level < RESOLUTION_COUNT)
	{
		count = ((WINDOW_WIDTH - 1) / resolution->scale[level] + 1) \
					* ((WINDOW_HEIGHT - 1) / resolution->scale[level] + 1) \
					- total_count;
		resolution->render_pixel[level] = malloc(sizeof(size_t) * count);
		if (resolution->render_pixel[level] == NULL)
		{
			print_log_errno(LOG_ERROR);
			return (false);
		}
		total_count += count;
		++level;
	}
	return (true);
}

static void	set_render_pixel(t_resolution *resolution)
{
	t_ivec2					pixel;
	enum e_resolution_level	level;
	size_t					count;

	ft_bzero(resolution->render_pixel_count, sizeof(size_t) * RESOLUTION_COUNT);
	pixel.height = 0;
	while (pixel.height < WINDOW_HEIGHT)
	{
		pixel.width = 0;
		while (pixel.width < WINDOW_WIDTH)
		{
			level = get_pixel_resolution_level(resolution, pixel);
			count = (resolution->render_pixel_count[level])++;
			resolution->render_pixel[level][count] = pixel;
			++(pixel.width);
		}
		++(pixel.height);
	}
}

static enum e_resolution_level	get_pixel_resolution_level(\
	t_resolution const *resolution, t_ivec2 pixel)
{
	enum e_resolution_level	level;

	level = 0;
	while (true)
	{
		if (pixel.height % resolution->scale[level] == 0 \
				&& pixel.width % resolution->scale[level] == 0)
		{
			return (level);
		}
		++level;
	}
}
