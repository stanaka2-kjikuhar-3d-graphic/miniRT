/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_texture_image.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 16:55:11 by stanaka2          #+#    #+#             */
/*   Updated: 2026/11/01 17:19:46 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

#include "mlx.h"
#include "ft_string.h"

#include "window.h"
#include "logger.h"

#include "./texture_private.h"
#include "../image_private.h"

static bool	create_image_from_xpm(t_image *image, char *xpm);

bool	create_texture_image(char *filepath, t_texture *texture)
{
	texture->image = malloc(sizeof(t_image));
	texture->filepath = ft_strdup(filepath);
	if (texture->image == NULL || texture->filepath == NULL)
	{
		print_log_errno(LOG_ERROR);
		free(texture->image);
		texture->image = NULL;
		free(texture->filepath);
		texture->filepath = NULL;
		return (false);
	}
	if (!create_image_from_xpm(texture->image, filepath))
	{
		free(texture->image);
		texture->image = NULL;
		free(texture->filepath);
		texture->filepath = NULL;
		return (false);
	}
	return (true);
}

static bool	create_image_from_xpm(t_image *image, char *xpm)
{
	image->ptr = mlx_xpm_file_to_image(\
					get_mlx_ptr(), xpm, &(image->width), &(image->height));
	if (image->ptr == NULL)
	{
		print_log_file(LOG_ERROR, xpm, ERROR_MLX_XPM_IMAGE);
		return (false);
	}
	image->pixel = mlx_get_data_addr(image->ptr, &(image->bits_per_pixel), \
										&(image->line_size), &(image->endian));
	if (image->pixel == NULL)
	{
		print_log_file(LOG_ERROR, xpm, ERROR_MLX_IMAGE_DATA);
		mlx_destroy_image(get_mlx_ptr(), image->ptr);
		return (false);
	}
	return (true);
}
