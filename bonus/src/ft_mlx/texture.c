/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 19:06:13 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/07 23:02:20 by stanaka2         ###   ########.fr       */
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

static t_dynamic_array	g_texture_dict = (t_dynamic_array){\
											.type_size = sizeof(t_texture_dict) \
										};

static bool	create_texture_dict(char *filepath, t_texture_dict *texture_dict);
static bool	create_image_from_xpm(t_image *image, char *xpm);

t_image	*get_texture(char *filepath)
{
	size_t			i;
	t_texture_dict	*texture_entry;

	i = 0;
	while (i < g_texture_dict.used)
	{
		texture_entry = access_dynamic_array(&g_texture_dict, i);
		if (ft_strcmp(filepath, texture_entry->filepath) == 0)
			return (texture_entry->texture);
		++i;
	}
	return (NULL);
}

bool	create_texture(char *filepath)
{
	t_texture_dict	texture_entry;

	if (get_texture(filepath) != NULL)
		return (true);
	if (!create_texture_dict(filepath, &texture_entry))
		return (false);
	if (!add_dynamic_array(&g_texture_dict, &texture_entry))
	{
		mlx_destroy_image(get_mlx_ptr(), texture_entry.texture->ptr);
		free(texture_entry.texture);
		free(texture_entry.filepath);
		return (false);
	}
	return (true);
}

static bool	create_texture_dict(char *filepath, t_texture_dict *texture_dict)
{
	texture_dict->texture = malloc(sizeof(t_image));
	texture_dict->filepath = ft_strdup(filepath);
	if (texture_dict->texture == NULL || texture_dict->filepath == NULL)
	{
		print_errno();
		free(texture_dict->texture);
		free(texture_dict->filepath);
		return (false);
	}
	if (!create_image_from_xpm(texture_dict->texture, filepath))
	{
		free(texture_dict->texture);
		free(texture_dict->filepath);
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

void	cleanup_textures(void)
{
	size_t			i;
	t_texture_dict	*entry;

	i = 0;
	while (i < g_texture_dict.used)
	{
		entry = access_dynamic_array(&g_texture_dict, i);
		free(entry->filepath);
		mlx_destroy_image(get_mlx_ptr(), entry->texture->ptr);
		free(entry->texture);
		++i;
	}
	cleanup_dynamic_array(&g_texture_dict);
}
