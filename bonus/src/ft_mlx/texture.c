/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 19:06:13 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/16 00:31:35 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

#include "mlx.h"
#include "ft_string.h"

#include "ft_mlx.h"
#include "ft_error.h"
#include "dynamic_array.h"

#include "./ft_mlx_private.h"


static t_dynamic_array	g_texture_dicts = (t_dynamic_array){\
											.data = NULL, \
											.capacity = 0, \
											.used = 0, \
											.type_size = sizeof(t_texture_dict) \
										};

static bool	create_image_from_xpm(t_image *image, char *xpm);

t_image	*get_texture(char *filepath)
{
	size_t			i;
	t_texture_dict	*texture_dict;

	i = 0;
	while (i < g_texture_dicts.used)
	{
		texture_dict = access_dynamic_array(&g_texture_dicts, i);
		if (ft_strcmp(filepath, texture_dict->filepath) == 0)
			return (texture_dict->texture);
		++i;
	}
	return (NULL);
}

bool	create_texture(char *filepath)
{
	t_texture_dict	texture_dict;

	if (get_texture(filepath) != NULL)
		return (true);
	texture_dict.texture = malloc(sizeof(t_image));
	texture_dict.filepath = ft_strdup(filepath);
	if (texture_dict.texture == NULL || texture_dict.filepath == NULL)
	{
		print_errno();
		free(texture_dict.texture);
		free(texture_dict.filepath);
		return (false);
	}
	if (!create_image_from_xpm(texture_dict.texture, filepath))
	{
		free(texture_dict.texture);
		free(texture_dict.filepath);
		return (false);
	}
	if (!add_dynamic_array(&g_texture_dicts, &texture_dict))
	{
		mlx_destroy_image(get_mlx_ptr(), texture_dict.texture->ptr);
		free(texture_dict.texture);
		free(texture_dict.filepath);
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
		print_texture_error(xpm, ERROR_MLX_XPM_IMAGE);
		return (false);
	}
	image->pixel = mlx_get_data_addr(image->ptr, &(image->bits_per_pixel), \
										&(image->line_size), &(image->endian));
	if (image->pixel == NULL)
	{
		print_texture_error(xpm, ERROR_MLX_IMAGE_DATA);
		mlx_destroy_image(get_mlx_ptr(), image->ptr);
		return (false);
	}
	return (true);
}

void	cleanup_texture_dict(void)
{
	size_t			i;
	t_texture_dict	*texture_dict;

	i = 0;
	while (i < g_texture_dicts.used)
	{
		texture_dict = access_dynamic_array(&g_texture_dicts, i);
		free(texture_dict->filepath);
		mlx_destroy_image(get_mlx_ptr(), texture_dict->texture->ptr);
		free(texture_dict->texture);
		++i;
	}
	cleanup_dynamic_array(&g_texture_dicts);
}
