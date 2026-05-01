/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_connection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 23:17:20 by stanaka2          #+#    #+#             */
/*   Updated: 2026/03/12 23:19:14 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	create_connection(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
	{
		print_error("");
		return (false);
	}
	return (true);
}
