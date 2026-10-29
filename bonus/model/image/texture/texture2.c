/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 14:44:31 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/18 08:48:13 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

#include "mlx.h"
#include "ft_string.h"

#include "image.h"
#include "window.h"
#include "logger.h"
#include "dynamic_array.h"
#include "texture.h"

#include "./texture_private.h"
#include "../image_private.h"

static bool	has_texture(char *filepath, t_texture_id *id);
static bool	create_texture_image(char *filepath, t_texture *texture_dict);
static bool	create_image_from_xpm(t_image *image, char *xpm);

bool	create_texture(char *filepath, t_texture_id *id)
{
	t_texture	texture;

	if (has_texture(filepath, id))
		return (true);
	if (!create_texture_image(filepath, &texture))
		return (false);
	if (!add_texture_id(get_mutable_texture_array()->used, &(texture.id)) \
		|| !add_dynamic_array(get_mutable_texture_array(), &texture))
	{
		mlx_destroy_image(get_mlx_ptr(), texture.image->ptr);
		free(texture.image);
		free(texture.filepath);
		return (false);
	}
	*id = texture.id;
	return (true);
}

static bool	has_texture(char *filepath, t_texture_id *id)
{
	size_t		i;
	t_texture	*texture;

	i = 0;
	while (i < get_mutable_texture_array()->used)
	{
		texture = access_dynamic_array(get_mutable_texture_array(), i);
		if (ft_strcmp(filepath, texture->filepath) == 0)
		{
			*id = texture->id;
			return (true);
		}
		++i;
	}
	return (false);
}

static bool	create_texture_image(char *filepath, t_texture *texture)
{
	texture->image = malloc(sizeof(t_image));
	texture->filepath = ft_strdup(filepath);
	if (texture->image == NULL || texture->filepath == NULL)
	{
		print_log_errno(LOG_ERROR);
		free(texture->image);
		free(texture->filepath);
		return (false);
	}
	if (!create_image_from_xpm(texture->image, filepath))
	{
		free(texture->image);
		free(texture->filepath);
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

void	cleanup_textures(void)
{
	size_t		i;
	t_texture	*texture;

	i = 0;
	while (i < get_mutable_texture_array()->used)
	{
		texture = access_dynamic_array(get_mutable_texture_array(), i);
		free(texture->filepath);
		mlx_destroy_image(get_mlx_ptr(), texture->image->ptr);
		free(texture->image);
		++i;
	}
	cleanup_dynamic_array(get_mutable_texture_array());
}
