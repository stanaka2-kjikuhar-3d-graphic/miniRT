/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 19:06:13 by stanaka2          #+#    #+#             */
/*   Updated: 2026/11/01 17:17:57 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

#include "mlx.h"
#include "ft_string.h"

#include "window.h"
#include "logger.h"
#include "dynamic_array.h"
#include "texture.h"

#include "./texture_private.h"
#include "../image_private.h"

static t_dynamic_array	g_textures = (t_dynamic_array){\
										.type_size = sizeof(t_texture) \
									};

static bool	has_texture(char *filepath, t_texture_id *id);

t_image	*get_texture(t_texture_id id)
{
	return (((t_texture *)access_dynamic_array(\
				&g_textures, get_texture_index(id)))->image);
}

bool	create_texture(char *filepath, t_texture_id *id)
{
	t_texture	texture;

	if (has_texture(filepath, id))
		return (true);
	if (!create_texture_image(filepath, &texture))
		return (false);
	if (!add_texture_id(g_textures.used, &(texture.id)) \
		|| !add_dynamic_array(&g_textures, &texture))
	{
		mlx_destroy_image(get_mlx_ptr(), texture.image->ptr);
		free(texture.image);
		texture.image = NULL;
		free(texture.filepath);
		texture.filepath = NULL;
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
	while (i < g_textures.used)
	{
		texture = access_dynamic_array(&g_textures, i);
		if (ft_strcmp(filepath, texture->filepath) == 0)
		{
			*id = texture->id;
			return (true);
		}
		++i;
	}
	return (false);
}

void	cleanup_textures(void)
{
	size_t		i;
	t_texture	*texture;

	i = 0;
	while (i < g_textures.used)
	{
		texture = access_dynamic_array(&g_textures, i);
		free(texture->filepath);
		mlx_destroy_image(get_mlx_ptr(), texture->image->ptr);
		free(texture->image);
		++i;
	}
	cleanup_dynamic_array(&g_textures);
}
