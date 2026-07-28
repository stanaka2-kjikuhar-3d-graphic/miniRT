/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 19:06:13 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/28 15:08:02 by stanaka2         ###   ########.fr       */
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

static t_texture_dict	*g_texture_dicts;
static size_t			g_capacity;
static size_t			g_count;

static bool	create_image_from_xpm(t_image *image, char *xpm);

t_image	*get_texture(char *filepath)
{
	size_t	i;

	i = 0;
	while (i < g_count)
	{
		if (ft_strcmp(filepath, g_texture_dicts[i].filepath) == 0)
			return (g_texture_dicts[i].texture);
		++i;
	}
	return (NULL);
}

bool	create_texture(char *filepath)
{
	if (get_texture(filepath) != NULL)
		return (true);
	if (g_count == g_capacity && !grow_dynamic_array(\
			(void **)(&g_texture_dicts), &g_capacity, sizeof(t_texture_dict)))
	{
		return (false);
	}
	g_texture_dicts[g_count].texture = malloc(sizeof(t_image));
	g_texture_dicts[g_count].filepath = ft_strdup(filepath);
	if (g_texture_dicts[g_count].texture == NULL \
		|| g_texture_dicts[g_count].filepath == NULL)
	{
		print_errno();
		free(g_texture_dicts[g_count].texture);
		free(g_texture_dicts[g_count].filepath);
		return (false);
	}
	if (!create_image_from_xpm(g_texture_dicts[g_count].texture, filepath))
	{
		free(g_texture_dicts[g_count].texture);
		free(g_texture_dicts[g_count].filepath);
		return (false);
	}
	++g_count;
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
	size_t	i;

	if (g_texture_dicts == NULL)
		return ;
	i = 0;
	while (i < g_count)
	{
		free(g_texture_dicts[i].filepath);
		mlx_destroy_image(get_mlx_ptr(), g_texture_dicts[i].texture->ptr);
		free(g_texture_dicts[i].texture);
		++i;
	}
	free(g_texture_dicts);
	g_texture_dicts = NULL;
	g_capacity = 0;
	g_count = 0;
}
