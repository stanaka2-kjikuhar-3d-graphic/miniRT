/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_virtical_pixels.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 03:25:46 by stanaka2          #+#    #+#             */
/*   Updated: 2026/04/05 19:33:20 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_ceiling(t_cub3d *cub3d, int win_x, const t_wall *wall);
void	draw_wall(t_cub3d *cub3d, int win_x, t_wall *wall);
void	draw_floor(t_cub3d *cub3d, int win_x, const t_wall *wall);

void	draw_virtical_pixels(t_cub3d *cub3d, int win_x, t_wall *wall)
{
	draw_ceiling(cub3d, win_x, wall);
	draw_wall(cub3d, win_x, wall);
	draw_floor(cub3d, win_x, wall);
}

void	draw_ceiling(t_cub3d *cub3d, int win_x, const t_wall *wall)
{
	const int	ceiling_color = mlx_get_color_value(\
						cub3d->mlx.mlx_ptr, cub3d->setting.ceiling_color.rgb);
	int			win_y;

	win_y = 0;
	while (win_y < wall->draw_start)
	{
		*get_pixel_addr(&(cub3d->mlx.win_img), win_x, win_y) = ceiling_color;
		win_y++;
	}
}

void	draw_wall(t_cub3d *cub3d, int win_x, t_wall *wall)
{
	double			texture_v;
	const double	step = (double)wall->texture->height / wall->height;
	int				win_y;

	texture_v = (wall->draw_start - wall->top) * step;
	win_y = wall->draw_start;
	while (win_y <= wall->draw_end)
	{
		wall->texture_pixel.y = (int)texture_v;
		if (wall->texture_pixel.y == wall->texture->height)
			wall->texture_pixel.y--;
		*get_pixel_addr(&(cub3d->mlx.win_img), win_x, win_y) \
			= *get_pixel_addr(\
				wall->texture, wall->texture_pixel.x, wall->texture_pixel.y);
		texture_v += step;
		win_y++;
	}
}

void	draw_floor(t_cub3d *cub3d, int win_x, const t_wall *wall)
{
	const int	floor_color = mlx_get_color_value(\
						cub3d->mlx.mlx_ptr, cub3d->setting.floor_color.rgb);
	int			win_y;

	win_y = wall->draw_end + 1;
	while (win_y < W_HEIGHT)
	{
		*get_pixel_addr(&(cub3d->mlx.win_img), win_x, win_y) = floor_color;
		win_y++;
	}
}
