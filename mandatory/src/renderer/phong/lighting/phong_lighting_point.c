/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_lighting_point.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 03:38:56 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/05 22:31:18 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "color.h"
#include "light.h"

#include "../phong_private.h"

static t_color	calc_diffuse_color(\
	t_hit const *hit, t_point_light const *light, float attenuation);

void	phong_lighting_point(\
	t_color *color, t_hit const *hit, t_point_light const *light)
{
	t_vec3	to_light;
	float	light_dist;
	t_vec3	light_dir;
	float	attenuation;

	to_light = vec3_sub(light->pos, hit->point);
	light_dist = vec3_length(to_light);
	light_dir = vec3_scale(1.0f / light_dist, to_light);
	attenuation = calc_point_light_attenuation(light, light_dist);
	if (!check_cutoff(light->radiance, attenuation) \
		&& !phong_shading(hit, light_dir, light_dist))
	{
		*color = add_color(*color, \
			calc_diffuse_color(hit, light, attenuation));
	}
}

static t_color	calc_diffuse_color(\
	t_hit const *hit, t_point_light const *light, float attenuation)
{
	float	dot;
	t_color	diffuse;

	dot = vec3_dot(hit->normal, \
						vec3_normalize(vec3_sub(light->pos, hit->point)));
	if (dot <= 0.0f)
		return ((t_color){.r = 0.0f, .g = 0.0f, .b = 0.0f});
	diffuse = scale_color(dot * attenuation, light->radiance);
	return (mul_color(hit->color, diffuse));
}
