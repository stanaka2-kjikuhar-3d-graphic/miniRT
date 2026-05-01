/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 00:36:47 by stanaka2          #+#    #+#             */
/*   Updated: 2026/04/06 16:59:55 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_cub3d	cub3d;

	if (argc != 2)
	{
		print_error(ERROR_ARG_USAGE);
		return (1);
	}
	ft_bzero(&cub3d, sizeof(t_cub3d));
	if (!parse_file(&cub3d, argv[1]))
		return (1);
	init_player(&(cub3d.map), &(cub3d.player));
	if (!ft_mlx_init(&(cub3d.mlx), &(cub3d.setting)))
	{
		cleanup_map(&(cub3d.map));
		cleanup_setting(&(cub3d.setting));
		return (1);
	}
	ft_mlx_hooks(&cub3d);
	ft_mlx_destroy(&(cub3d.mlx));
	cleanup_map(&(cub3d.map));
	cleanup_setting(&(cub3d.setting));
	return (0);
}
