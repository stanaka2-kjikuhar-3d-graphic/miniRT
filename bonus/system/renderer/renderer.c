/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 21:38:45 by stanaka2          #+#    #+#             */
/*   Updated: 2026/11/05 21:10:53 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <pthread.h>
#include <stddef.h>
#include <stdint.h>

#include "mlx.h"

#include "config.h"
#include "renderer.h"
#include "viewport.h"
#include "vector.h"
#include "logger.h"
#include "window.h"
#include "window_buffer.h"

#include "./renderer_private.h"

static bool	multi_threads_rendering(void);
static void	*rendering(void *arg);
static bool	get_pixel(size_t i, t_ivec2 *pixel);

bool	renderer(void)
{
	if (get_viewport()->sample_count < MAX_SAMPLE_COUNT)
	{
		if (!multi_threads_rendering())
			return (false);
		set_sample_count(get_buffering_mode());
		resolve_viewport_to_window_buffer(MAIN_WINDOW_BUFFER);
		mlx_put_image_to_window(get_mlx_ptr(), get_win_ptr(), \
					get_window_buffer_ptr(MAIN_WINDOW_BUFFER), 0, 0);
		increment_resolution_level();
	}
	return (true);
}

static bool	multi_threads_rendering(void)
{
	bool					res;
	pthread_t				threads[THREAD_COUNT];
	static t_render_thread	states[THREAD_COUNT];
	size_t					i;

	res = true;
	i = 0;
	while (i < THREAD_COUNT)
	{
		states[i].id = (int)i;
		if (pthread_create(&(threads[i]), NULL, rendering, &(states[i])) != 0)
		{
			print_log_errno(LOG_ERROR);
			res = false;
			break ;
		}
		++i;
	}
	while (i > 0)
		pthread_join(threads[--i], NULL);
	return (res);
}

static void	*rendering(void *arg)
{
	t_render_thread		*state;
	t_ivec2				pixel;
	size_t				i;
	uint32_t			seed;

	state = (t_render_thread *)arg;
	seed = state->seed;
	if (seed == 0)
		seed = ((uint32_t)(PIXEL_SAMPLE_SEED + state->id) * 2654435761u) | 1u;
	i = state->id;
	while (get_pixel(i, &pixel))
	{
		render_pixel(pixel, &seed);
		i += THREAD_COUNT;
	}
	state->seed = seed;
	return (NULL);
}

static bool	get_pixel(size_t i, t_ivec2 *pixel)
{
	t_resolution const	*resolution;

	resolution = &(get_viewport()->resolution);
	if (resolution->level < RESOLUTION_COUNT)
	{
		if (resolution->render_pixel_count[resolution->level] <= i)
			return (false);
		*pixel = resolution->render_pixel[resolution->level][i];
		return (true);
	}
	else
	{
		pixel->height = (int)(i / (size_t)WINDOW_WIDTH);
		pixel->width = (int)(i % (size_t)WINDOW_WIDTH);
		if (WINDOW_HEIGHT <= pixel->height)
			return (false);
		return (true);
	}
}
