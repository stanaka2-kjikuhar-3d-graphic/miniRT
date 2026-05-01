/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_assets.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 23:17:17 by stanaka2          #+#    #+#             */
/*   Updated: 2026/03/23 03:49:00 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	create_xpm_image(t_mlx *mlx, t_img *img, char *xpm);

bool	create_assets(t_mlx *mlx, t_setting *setting)
{
	if (!create_xpm_image(mlx, \
			&(mlx->assets.north_wall), setting->north_texture) \
		|| !create_xpm_image(mlx, \
			&(mlx->assets.south_wall), setting->south_texture) \
		|| !create_xpm_image(mlx, \
			&(mlx->assets.west_wall), setting->west_texture) \
		|| !create_xpm_image(mlx, \
			&(mlx->assets.east_wall), setting->east_texture))
	{
		return (false);
	}
	return (true);
}

static bool	create_xpm_image(t_mlx *mlx, t_img *img, char *xpm)
{
	init_image_info(img, TEXTURE_SIZE, TEXTURE_SIZE);
	img->img_ptr = mlx_xpm_file_to_image(\
				mlx->mlx_ptr, xpm, &(img->width), &(img->height));
	if (img->img_ptr == NULL)
	{
		print_error("");
		return (false);
	}
	img->pixel = mlx_get_data_addr(img->img_ptr, \
					&(img->bits_per_pixel), &(img->size_line), &(img->endian));
	if (img->pixel == NULL)
	{
		print_error("");
		return (false);
	}
	return (true);
}
