/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 16:03:43 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/18 08:10:49 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "mlx.h"
#include "ft_string.h"

#include "logger.h"
#include "window.h"
#include "window_buffer.h"

#include "../image_private.h"

static t_image	g_window_buffers[WINDOW_BUFFER_COUNT];

t_image	*get_window_buffer(enum e_window_buffer_id id)
{
	return (&(g_window_buffers[id]));
}

void	*get_window_buffer_ptr(enum e_window_buffer_id id)
{
	return (g_window_buffers[id].ptr);
}

bool	create_window_buffer(enum e_window_buffer_id id, int width, int height)
{
	t_image	*image;

	image = &(g_window_buffers[id]);
	image->width = width;
	image->height = height;
	image->ptr = mlx_new_image(get_mlx_ptr(), image->width, image->height);
	if (image->ptr == NULL)
	{
		print_log_msg(LOG_ERROR, ERROR_MLX_IMAGE);
		ft_bzero(image, sizeof(t_image));
		return (false);
	}
	image->pixel = mlx_get_data_addr(image->ptr, &(image->bits_per_pixel), \
										&(image->line_size), &(image->endian));
	if (image->pixel == NULL)
	{
		print_log_msg(LOG_ERROR, ERROR_MLX_IMAGE_DATA);
		mlx_destroy_image(get_mlx_ptr(), image->ptr);
		ft_bzero(image, sizeof(t_image));
		return (false);
	}
	return (true);
}

void	cleanup_window_buffers(void)
{
	enum e_window_buffer_id	id;

	id = 0;
	while (id < WINDOW_BUFFER_COUNT)
	{
		if (g_window_buffers[id].ptr != NULL)
		{
			mlx_destroy_image(get_mlx_ptr(), g_window_buffers[id].ptr);
			ft_bzero(&(g_window_buffers[id]), sizeof(t_image));
		}
		++id;
	}
}
