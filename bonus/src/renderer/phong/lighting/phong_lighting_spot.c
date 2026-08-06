/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_lighting_spot.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 03:39:27 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/05 23:12:33 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "ft_math.h"

#include "config.h"
#include "color.h"
#include "ray.h"
#include "light.h"

#include "../phong_private.h"

static t_color	calc_diffuse_color(t_hit const *hit, \
					t_spot_light const *light, float attenuation);
static t_color	calc_specular_color(t_ray const *ray, t_hit const *hit, \
					t_spot_light const *light, float attenuation);

void	phong_lighting_spot(t_color *color, \
	t_ray const *ray, t_hit const *hit, t_spot_light const *light)
{
	t_vec3	to_light;
	float	light_dist;
	t_vec3	light_dir;
	float	attenuation;

	to_light = vec3_sub(light->pos, hit->point);
	light_dist = vec3_length(to_light);
	light_dir = vec3_scale(1.0f / light_dist, to_light);
	attenuation = calc_spot_light_attenuation(\
		light, light_dist, vec3_dot(light_dir, vec3_scale(-1, light->dir)));
	if (!check_cutoff(light->radiance, attenuation)
		&& !phong_shading(hit, light_dir, light_dist))
	{
		*color = add_color(*color, \
			calc_diffuse_color(hit, light, attenuation));
		*color = add_color(*color, \
			calc_specular_color(ray, hit, light, attenuation));
	}
}

static t_color	calc_diffuse_color(\
	t_hit const *hit, t_spot_light const *light, float attenuation)
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

static t_color	calc_specular_color(t_ray const *ray, \
	t_hit const *hit, t_spot_light const *light, float attenuation)
{
	t_vec3	to_light;
	float	dot;
	t_color	specular;

	to_light = vec3_normalize(vec3_sub(light->pos, hit->point));
	if (vec3_dot(hit->normal, to_light) <= 0.0f)
		return ((t_color){.r = 0.0f, .g = 0.0f, .b = 0.0f});
	dot = calc_specular_dot(ray, hit, to_light);
	if (dot <= 0.0f)
		return ((t_color){.r = 0.0f, .g = 0.0f, .b = 0.0f});
	specular = scale_color(\
				powf(dot, hit->object->material.shininess) * attenuation, \
				light->radiance);
	return (specular);
}
