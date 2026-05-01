/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 20:34:26 by stanaka2          #+#    #+#             */
/*   Updated: 2026/04/05 19:10:23 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray_casting(t_cub3d *cub3d);

void	draw_game(t_cub3d *cub3d)
{
	ray_casting(cub3d);
	mlx_put_image_to_window(cub3d->mlx.mlx_ptr, \
							cub3d->mlx.win_ptr, \
							cub3d->mlx.win_img.img_ptr, \
							0, 0);
}

void	ray_casting(t_cub3d *cub3d)
{
	int		win_x;
	double	camera_x;
	t_dvec2	ray;
	t_hit	hit;
	t_wall	wall;

	win_x = 0;
	while (win_x < W_WIDTH)
	{
		camera_x = (((double)win_x / W_WIDTH) - 0.5) * 2.0;
		ray = dvec2_add(cub3d->player.dir, \
								dvec2_scale(cub3d->player.plane, camera_x));
		hit = dda_algorithm(cub3d, ray);
		wall = compute_wall(cub3d, ray, &hit);
		draw_virtical_pixels(cub3d, win_x, &wall);
		win_x++;
	}
}
