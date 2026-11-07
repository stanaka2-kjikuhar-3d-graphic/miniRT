/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 16:55:14 by stanaka2          #+#    #+#             */
/*   Updated: 2026/11/01 17:13:41 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "mlx.h"

#include "logger.h"
#include "window.h"

#include "../image_private.h"

bool	create_image(t_image *image)
{
	image->ptr = mlx_new_image(get_mlx_ptr(), image->width, image->height);
	if (image->ptr == NULL)
	{
		print_log_msg(LOG_ERROR, ERROR_MLX_IMAGE);
		return (false);
	}
	image->pixel = mlx_get_data_addr(image->ptr, &(image->bits_per_pixel), \
										&(image->line_size), &(image->endian));
	if (image->pixel == NULL)
	{
		print_log_msg(LOG_ERROR, ERROR_MLX_IMAGE_DATA);
		mlx_destroy_image(get_mlx_ptr(), image->ptr);
		image->ptr = NULL;
		return (false);
	}
	return (true);
}
