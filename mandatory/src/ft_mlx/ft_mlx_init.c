/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 18:25:30 by stanaka2          #+#    #+#             */
/*   Updated: 2026/03/13 01:39:26 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	ft_mlx_init(t_mlx *mlx, t_setting *setting)
{
	if (!create_connection(mlx) \
		|| !create_window(mlx) \
		|| !create_win_image(mlx, &(mlx->win_img)) \
		|| !create_assets(mlx, setting))
	{
		ft_mlx_destroy(mlx);
		return (false);
	}
	return (true);
}
