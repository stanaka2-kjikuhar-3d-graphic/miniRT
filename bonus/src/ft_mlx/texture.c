/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 19:06:13 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/27 21:18:32 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

#include "ft_stdlib.h"
#include "ft_string.h"

#include "ft_mlx.h"
#include "ft_error.h"

#include "./ft_mlx_private.h"

static t_texture_dict	*g_texture_dict;
static size_t			g_array_size;
static size_t			g_count;

static bool	allocate_texture_dict(size_t add_count);
static bool	create_image_from_xpm(t_image *image, char *xpm);

t_image	*get_texture(char *filepath)
{
	size_t	i;

	i = 0;
	while (i < g_count)
	{
		if (ft_strcmp(filepath, g_texture_dict[i].filepath) == 0)
			return (&(g_texture_dict[i].texture));
		++i;
	}
	return (NULL);
}

bool	add_texture(char *filepath)
{
	if (get_texture(filepath) != NULL)
		return (true);
	if (g_count == g_array_size)
	{
		if (!allocate_texture_dict(16))
		{
			g_count = 0;
			return (false);
		}
	}
	g_texture_dict[g_count].filepath = ft_strdup(filepath);
	if (g_texture_dict[g_count].filepath == NULL)
	{
		print_errno();
		return (false);
	}
	if (create_image_from_xpm(&(g_texture_dict[g_count].texture), filepath))
	{
		free(g_texture_dict[g_count].filepath);
		return (false);
	}
	++g_count;
	return (true);
}

static bool	allocate_texture_dict(size_t add_count)
{
	if (g_texture_dict == NULL)
	{
		g_texture_dict = malloc(sizeof(t_texture_dict) * add_count);
		if (g_texture_dict == NULL)
		{
			print_errno();
			return (false);
		}
		g_array_size = add_count;
	}
	else
	{
		g_texture_dict = ft_reallocf(g_texture_dict, \
						sizeof(t_texture_dict) * g_array_size, \
						sizeof(t_texture_dict) * (g_array_size + add_count));
		if (g_texture_dict == NULL)
		{
			print_errno();
			g_array_size = 0;
			return (false);
		}
		g_array_size += add_count;
	}
	return (true);
}

static bool	create_image_from_xpm(t_image *image, char *xpm)
{
	image->ptr = mlx_xpm_file_to_image(
					get_mlx_ptr(), xpm, &(image->width), &(image->height));
	if (image->ptr == NULL)
	{
		print_error(ERROR_MLX_TEXTURE_LOAD);
		return (false);
	}
	image->pixel = mlx_get_data_addr(image->ptr, &(image->bits_per_pixel), 
										&(image->line_size), &(image->endian));
	if (image->pixel == NULL)
	{
		print_error(ERROR_MLX_IMAGE_DATA);
		mlx_destroy_image(get_mlx_ptr(), image->ptr);
		return (false);
	}
	return (true);
}

void	cleanup_texture_dict(void)
{
	size_t	i;

	if (g_texture_dict == NULL)
		return ;
	i = 0;
	while (i < g_count)
	{
		free(g_texture_dict[i].filepath);
		mlx_destroy_image(get_mlx_ptr(), g_texture_dict[i].image.ptr);
		++i;
	}
	free(g_texture_dict);
	g_texture_dict = NULL;
	g_array_size = 0;
	g_count = 0;
}
