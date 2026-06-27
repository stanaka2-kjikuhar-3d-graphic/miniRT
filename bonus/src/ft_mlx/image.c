/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 16:03:43 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/28 00:31:55 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "mlx.h"
#include "ft_string.h"

#include "ft_error.h"
#include "ft_mlx.h"

#include "./ft_mlx_private.h"

static t_image	g_images[IMG_COUNT];

t_image	*get_image(enum e_image_id id)
{
	return (&(g_images[id]));
}

bool	create_image(enum e_image_id id, int width, int height)
{
	t_image	*image;

	image = &(g_images[id]);
	image->width = width;
	image->height = height;
	image->ptr = mlx_new_image(get_mlx_ptr(), image->width, image->height);
	if (image->ptr == NULL)
	{
		print_error(ERROR_MLX_IMAGE);
		ft_bzero(image, sizeof(t_image));
		return (false);
	}
	image->pixel = mlx_get_data_addr(image->ptr, &(image->bits_per_pixel), \
										&(image->line_size), &(image->endian));
	if (image->pixel == NULL)
	{
		print_error(ERROR_MLX_IMAGE_DATA);
		mlx_destroy_image(get_mlx_ptr(), image->ptr);
		ft_bzero(image, sizeof(t_image));
		return (false);
	}
	return (true);
}

void	cleanup_images(void)
{
	enum e_image_id	id;

	id = 0;
	while (id < IMG_COUNT)
	{
		if (g_images[id].ptr != NULL)
		{
			mlx_destroy_image(get_mlx_ptr(), g_images[id].ptr);
			ft_bzero(&(g_images[id]), sizeof(t_image));
		}
		++id;
	}
}



https://zenn.dev/nekosato/books/816dcc4efcab67/viewer/9fbaf1