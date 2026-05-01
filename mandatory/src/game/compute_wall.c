/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 03:12:42 by stanaka2          #+#    #+#             */
/*   Updated: 2026/04/05 19:11:24 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

const t_img	*select_texture(\
	const t_cub3d *cub3d, t_dvec2 ray, const t_hit *hit);
double		calc_texture_u(\
	const t_cub3d *cub3d, t_dvec2 ray, const t_hit *hit);

t_wall	compute_wall(const t_cub3d *cub3d, t_dvec2 ray, const t_hit *hit)
{
	t_wall	wall;
	double	texture_u;

	wall.texture = select_texture(cub3d, ray, hit);
	texture_u = calc_texture_u(cub3d, ray, hit);
	wall.texture_pixel.x = (int)(wall.texture->width * texture_u);
	if (wall.texture_pixel.x == wall.texture->width)
		wall.texture_pixel.x--;
	wall.height = (int)(W_HEIGHT / hit->perp_wall_dist);
	wall.top = (W_HEIGHT - wall.height) / 2;
	wall.draw_start = wall.top;
	if (wall.draw_start < 0)
		wall.draw_start = 0;
	wall.bottom = wall.top + wall.height - 1;
	wall.draw_end = wall.bottom;
	if (wall.draw_end >= W_HEIGHT)
		wall.draw_end = W_HEIGHT - 1;
	return (wall);
}

const t_img	*select_texture(const t_cub3d *cub3d, t_dvec2 ray, const t_hit *hit)
{
	if (hit->side == X_SIDE)
	{
		if (ray.x > 0)
			return (&(cub3d->mlx.assets.west_wall));
		else
			return (&(cub3d->mlx.assets.east_wall));
	}
	else
	{
		if (ray.y > 0)
			return (&(cub3d->mlx.assets.north_wall));
		else
			return (&(cub3d->mlx.assets.south_wall));
	}
}

double	calc_texture_u(const t_cub3d *cub3d, t_dvec2 ray, const t_hit *hit)
{
	double	wall_hit_pos;
	double	texture_u;

	if (hit->side == X_SIDE)
		wall_hit_pos = cub3d->player.pos.y + hit->perp_wall_dist * ray.y;
	else
		wall_hit_pos = cub3d->player.pos.x + hit->perp_wall_dist * ray.x;
	if ((hit->side == X_SIDE && ray.x < 0) \
		|| (hit->side == Y_SIDE && ray.y > 0))
	{
		texture_u = 1.0 - (wall_hit_pos - floor(wall_hit_pos));
	}
	else
		texture_u = wall_hit_pos - floor(wall_hit_pos);
	return (texture_u);
}
