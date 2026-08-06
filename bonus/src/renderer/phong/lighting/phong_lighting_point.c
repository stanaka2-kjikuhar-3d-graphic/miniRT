/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_lighting_point.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 03:38:56 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/06 19:35:11 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "config.h"
#include "color.h"
#include "ray.h"
#include "light.h"

#include "../phong_private.h"

static t_color	calc_diffuse_color(\
	t_hit const *hit, t_point_light const *light, float attenuation);
static t_color	calc_specular_color(t_ray const *ray, t_hit const *hit, \
	t_point_light const *light, float attenuation);
static t_color	calc_phong_specular_color(t_ray const *ray, t_hit const *hit, \
	t_point_light const *light, float attenuation);
static t_color	calc_blinn_phong_specular_color(t_ray const *ray, \
	t_hit const *hit, t_point_light const *light, float attenuation);

void	phong_lighting_point(t_color *color, \
	t_ray const *ray, t_hit const *hit, t_point_light const *light)
{
	t_vec3	to_light;
	float	light_dist;
	t_vec3	light_dir;
	float	attenuation;

	to_light = vec3_sub(light->pos, hit->point);
	light_dist = vec3_length(to_light);
	light_dir = vec3_div(light_dist, to_light);
	if (!phong_shading(hit, light_dir, light_dist))
	{
		attenuation = calc_point_light_attenuation(light, light_dist);
		*color = add_color(*color, calc_diffuse_color(hit, light, attenuation));
		*color = add_color(*color, \
			calc_specular_color(ray, hit, light, attenuation));
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

static t_color	calc_specular_color(t_ray const *ray, t_hit const *hit, \
	t_point_light const *light, float attenuation)
{
	if (RENDERING_MODEL == BLINN_PHONG_MODEL)
		return (calc_blinn_phong_specular_color(ray, hit, light, attenuation));
	return (calc_phong_specular_color(ray, hit, light, attenuation));
}

static t_color	calc_phong_specular_color(t_ray const *ray, t_hit const *hit, \
	t_point_light const *light, float attenuation)
{
	t_vec3	to_light;
	t_vec3	reflection;
	float	dot;
	t_color	specular;

	to_light = vec3_normalize(vec3_sub(light->pos, hit->point));
	if (vec3_dot(hit->normal, to_light) <= 0.0f)
		return ((t_color){.r = 0.0f, .g = 0.0f, .b = 0.0f});
	reflection = vec3_normalize(vec3_sub(\
					vec3_scale(2 * vec3_dot(to_light, hit->normal), \
						hit->normal), to_light));
	dot = vec3_dot(vec3_scale(-1.0f, ray->dir), reflection);
	if (dot <= 0.0f)
		return ((t_color){.r = 0.0f, .g = 0.0f, .b = 0.0f});
	specular = scale_color(\
					powf(dot, hit->object->material.shininess) * attenuation, \
					light->radiance);
	return (specular);
}

static t_color	calc_blinn_phong_specular_color(t_ray const *ray, \
	t_hit const *hit, t_point_light const *light, float attenuation)
{
	t_vec3	to_light;
	t_vec3	halfway;
	float	dot;
	t_color	specular;

	to_light = vec3_normalize(vec3_sub(light->pos, hit->point));
	if (vec3_dot(hit->normal, to_light) <= 0.0f)
		return ((t_color){.r = 0.0f, .g = 0.0f, .b = 0.0f});
	halfway = vec3_normalize(vec3_add(vec3_scale(-1.0f, ray->dir), to_light));
	dot = vec3_dot(hit->normal, halfway);
	if (dot <= 0.0f)
		return ((t_color){.r = 0.0f, .g = 0.0f, .b = 0.0f});
	specular = scale_color(\
					powf(dot, hit->object->material.shininess) * attenuation, \
					light->radiance);
	return (specular);
}
