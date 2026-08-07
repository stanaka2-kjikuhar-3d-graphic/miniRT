/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 21:38:45 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/07 23:39:23 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <pthread.h>

#include "mlx.h"

#include "config.h"
#include "ft_mlx.h"
#include "renderer.h"
#include "viewport.h"
#include "vector.h"
#include "ft_error.h"

#include "./renderer_private.h"

static bool	multi_threads_rendering(void);
static void	*redering(void *arg);

bool	renderer(void)
{
	if (check_render_flag())
	{
		if (!multi_threads_rendering())
			return (false);
		mlx_put_image_to_window(\
			get_mlx_ptr(), get_win_ptr(), get_image(IMG_WINDOW)->ptr, 0, 0);
		set_render_flag(false);
	}
	return (true);
}

static bool	multi_threads_rendering(void)
{
	bool		res;
	pthread_t	threads[THREAD_COUNT];
	int			ids[THREAD_COUNT];
	size_t		i;

	res = true;
	i = 0;
	while (i < THREAD_COUNT)
	{
		ids[i] = (int)i;
		if (pthread_create(&(threads[i]), NULL, redering, &(ids[i])) != 0)
		{
			print_errno();
			res = false;
			break ;
		}
		++i;
	}
	while (i > 0)
		pthread_join(threads[--i], NULL);
	return (res);
}

static void	*redering(void *arg)
{
	t_viewport const	*viewport;
	int					pixel_num;
	t_ivec2				pixel;

	viewport = get_viewport();
	pixel_num = *((int *)arg);
	while (pixel_num < viewport->pixel_count)
	{
		pixel.y = pixel_num / viewport->pixel_size.x;
		pixel.x = pixel_num % viewport->pixel_size.x;
		phong(pixel);
		pixel_num += THREAD_COUNT;
	}
	return (NULL);
}
