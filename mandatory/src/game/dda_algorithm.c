/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 01:06:04 by stanaka2          #+#    #+#             */
/*   Updated: 2026/04/05 19:39:06 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_ivec2	calc_step(t_dvec2 ray);
t_dvec2	calc_initial_distance(\
	t_dvec2 ray, t_dvec2 delta_dist, const t_player *player);
bool	hit_wall(\
	const t_cub3d *cub3d, t_hit *hit, t_hit_side side, double ray_len);

t_hit	dda_algorithm(const t_cub3d *cub3d, t_dvec2 ray)
{
	t_hit			hit;
	const double	ray_len = dvec2_length(ray);
	const t_dvec2	delta_dist = dvec2(\
						fabs(ray_len / ray.x), fabs(ray_len / ray.y));
	const t_ivec2	step = calc_step(ray);

	hit.pos = ivec2(cub3d->player.pos.x, cub3d->player.pos.y);
	hit.wall_dist = calc_initial_distance(ray, delta_dist, &(cub3d->player));
	while (true)
	{
		if (hit.wall_dist.x < hit.wall_dist.y)
		{
			hit.pos.x += step.x;
			if (hit_wall(cub3d, &hit, X_SIDE, ray_len))
				return (hit);
			hit.wall_dist.x += delta_dist.x;
		}
		else
		{
			hit.pos.y += step.y;
			if (hit_wall(cub3d, &hit, Y_SIDE, ray_len))
				return (hit);
			hit.wall_dist.y += delta_dist.y;
		}
	}
}

t_ivec2	calc_step(t_dvec2 ray)
{
	t_ivec2	step;

	if (ray.x > 0)
		step.x = 1;
	else
		step.x = -1;
	if (ray.y > 0)
		step.y = 1;
	else
		step.y = -1;
	return (step);
}

// pos.x, pos.y >= 0
t_dvec2	calc_initial_distance(\
	t_dvec2 ray, t_dvec2 delta_dist, const t_player *player)
{
	t_dvec2	dist;

	if (ray.x > 0)
		dist.x = (1.0 - (player->pos.x - floor(player->pos.x))) * delta_dist.x;
	else
		dist.x = (player->pos.x - floor(player->pos.x)) * delta_dist.x;
	if (ray.y > 0)
		dist.y = (1.0 - (player->pos.y - floor(player->pos.y))) * delta_dist.y;
	else
		dist.y = (player->pos.y - floor(player->pos.y)) * delta_dist.y;
	return (dist);
}

bool	hit_wall(\
	const t_cub3d *cub3d, t_hit *hit, t_hit_side side, double ray_len)
{
	if (cub3d->map.data[hit->pos.y][hit->pos.x] == MAP_WALL)
	{
		if (side == X_SIDE)
			hit->perp_wall_dist = hit->wall_dist.x / ray_len;
		else
			hit->perp_wall_dist = hit->wall_dist.y / ray_len;
		hit->side = side;
		return (true);
	}
	return (false);
}
