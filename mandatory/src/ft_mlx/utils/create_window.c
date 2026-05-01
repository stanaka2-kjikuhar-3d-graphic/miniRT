/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 23:17:36 by stanaka2          #+#    #+#             */
/*   Updated: 2026/03/12 23:19:02 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	create_window(t_mlx *mlx)
{
	mlx->width = W_WIDTH;
	mlx->height = W_HEIGHT;
	mlx->win_ptr = mlx_new_window(
			mlx->mlx_ptr, mlx->width, mlx->height, "cub3D");
	if (mlx->win_ptr == NULL)
	{
		print_error("");
		return (false);
	}
	return (true);
}
