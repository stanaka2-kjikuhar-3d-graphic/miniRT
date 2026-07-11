/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_lighting_spot.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 03:39:27 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/03 04:10:26 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "ft_math.h"

#include "config.h"
#include "color.h"
#include "ray.h"
#include "light.h"

#include "../phong_private.h"

static t_color	calc_diffuse_color(\
	t_hit const *hit, t_spot_light const *light);
static t_color	calc_specular_color(\
	t_ray const *ray, t_hit const *hit, t_spot_light const *light);

void	phong_lighting_spot(t_color *color, \
	t_ray const *ray, t_hit const *hit, t_spot_light const *light)
{
	t_vec3	to_light;
	float	light_dist;
	t_vec3	light_dir;
	float	dot;

	to_light = vec3_sub(light->pos, hit->point);
	light_dist = vec3_length(to_light);
	light_dir = vec3_scale(1.0f / light_dist, to_light);
	if (!phong_shading(hit, light_dir, light_dist))
	{
		dot = vec3_dot(light_dir, vec3_scale(-1, light->dir));
		if (acosf(dot) * RAD_TO_DEG < light->angle.outer / 2.0f)
		{
			*color = add_color(add_color(\
						*color, \
						calc_diffuse_color(hit, light)), \
						calc_specular_color(ray, hit, light) \
					);
		}
	}
}

static t_color	calc_diffuse_color(\
	t_hit const *hit, t_spot_light const *light)
{
	float	dot;
	t_color	diffuse;

	dot = vec3_dot(hit->normal, \
						vec3_normalize(vec3_sub(light->pos, hit->point)));
	if (dot <= 0.0f)
		return ((t_color){.r = 0.0f, .g = 0.0f, .b = 0.0f});
	diffuse = scale_color(dot, light->radiance);
	return (mul_color(hit->color, diffuse));
}

static t_color	calc_specular_color(\
	t_ray const *ray, t_hit const *hit, t_spot_light const *light)
{
	t_vec3	from_light;
	t_vec3	reflection;
	float	dot;
	t_color	specular;

	from_light = vec3_normalize(vec3_sub(light->pos, hit->point));
	if (vec3_dot(hit->normal, from_light) <= 0.0f)
		return ((t_color){.r = 0.0f, .g = 0.0f, .b = 0.0f});
	reflection = vec3_normalize(vec3_sub(\
					vec3_scale(2 * vec3_dot(from_light, hit->normal), \
						hit->normal), from_light));
	dot = vec3_dot(vec3_scale(-1, ray->dir), reflection);
	if (dot <= 0.0f)
		return ((t_color){.r = 0.0f, .g = 0.0f, .b = 0.0f});
	specular = scale_color(powf(dot, SHININESS), light->radiance);
	return (specular);
}
