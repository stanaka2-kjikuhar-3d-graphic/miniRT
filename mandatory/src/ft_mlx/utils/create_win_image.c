/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_win_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 23:17:07 by stanaka2          #+#    #+#             */
/*   Updated: 2026/03/23 03:56:36 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	create_win_image(t_mlx *mlx, t_img *win_img)
{
	init_image_info(win_img, W_WIDTH, W_HEIGHT);
	win_img->img_ptr = mlx_new_image(mlx->mlx_ptr, \
							win_img->width, win_img->height);
	if (win_img->img_ptr == NULL)
	{
		print_error("");
		return (false);
	}
	win_img->pixel = mlx_get_data_addr(win_img->img_ptr, \
		&(win_img->bits_per_pixel), &(win_img->size_line), &(win_img->endian));
	if (win_img->pixel == NULL)
	{
		print_error("");
		return (false);
	}
	return (true);
}
