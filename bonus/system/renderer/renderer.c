/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 21:38:45 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/31 21:28:14 by kjikuhar         ###   ########.fr       */
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

bool	renderer(void)
{
	if (check_render_flag())
	{
		if (!multi_threads_rendering())
			return (false);
		mlx_put_image_to_window(get_mlx_ptr(), get_win_ptr(), \
					get_window_buffer_ptr(MAIN_WINDOW_BUFFER), 0, 0);
		set_render_flag(false);
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
	t_viewport const	*viewport;
	t_render_thread		*state;
	int					pixel_num;
	t_ivec2				pixel;
	uint32_t			seed;

	viewport = get_viewport();
	state = (t_render_thread *)arg;
	seed = state->seed;
	if (seed == 0)
		seed = ((uint32_t)(PIXEL_SAMPLE_SEED + state->id) * 2654435761u) | 1u;
	pixel_num = state->id;
	while (pixel_num < viewport->pixel_count)
	{
		pixel.y = pixel_num / viewport->pixel_size.x;
		pixel.x = pixel_num % viewport->pixel_size.x;
		render_pixel(pixel, &seed);
		pixel_num += THREAD_COUNT;
	}
	state->seed = seed;
	return (NULL);
}
