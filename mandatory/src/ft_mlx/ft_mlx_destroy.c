/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 18:25:42 by stanaka2          #+#    #+#             */
/*   Updated: 2026/03/13 01:40:29 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_mlx_destroy(t_mlx *mlx)
{
	if (mlx->assets.north_wall.img_ptr != NULL)
		mlx_destroy_image(mlx->mlx_ptr, mlx->assets.north_wall.img_ptr);
	if (mlx->assets.south_wall.img_ptr != NULL)
		mlx_destroy_image(mlx->mlx_ptr, mlx->assets.south_wall.img_ptr);
	if (mlx->assets.west_wall.img_ptr != NULL)
		mlx_destroy_image(mlx->mlx_ptr, mlx->assets.west_wall.img_ptr);
	if (mlx->assets.east_wall.img_ptr != NULL)
		mlx_destroy_image(mlx->mlx_ptr, mlx->assets.east_wall.img_ptr);
	if (mlx->win_img.img_ptr != NULL)
		mlx_destroy_image(mlx->mlx_ptr, mlx->win_img.img_ptr);
	if (mlx->win_ptr != NULL)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	if (mlx->mlx_ptr != NULL)
	{
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
	}
}
