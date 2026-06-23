/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 00:45:12 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/23 21:37:20 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stddef.h>

#include "config.h"
#include "color.h"
#include "ray.h"
#include "light.h"

#include "./phong_private.h"

static t_color	calc_ambient_color(\
	t_hit const *hit, t_ambient_light const *light);
static t_color	calc_diffuse_color(\
	t_hit const *hit, t_point_light const *light);
static t_color	calc_specular_color(\
	t_ray const *ray, t_hit const *hit, t_point_light const *light);

t_color	lighting(t_ray const *ray, t_hit const *hit)
{
	t_color			color;
	t_light const	*light;

	color = (t_color){.r = 0.0, .g = 0.0, .b = 0.0};
	light = NULL;
	while (get_next_light(&light))
	{
		if (light->type == AMBIENT_LIGHT)
		{
			color = add_color(color, \
						calc_ambient_color(hit, &(light->ambient)));
		}
		else if (light->type == POINT_LIGHT \
			&& !shadowing(hit, &(light->point)))
		{
			color = add_color(color, \
						calc_diffuse_color(hit, &(light->point)));
			color = add_color(color, \
						calc_specular_color(ray, hit, &(light->point)));
		}
	}
	return (color);
}

static t_color	calc_ambient_color(\
	t_hit const *hit, t_ambient_light const *light)
{
	t_color	ambient;

	ambient = light->radiance;
	return (mul_color(hit->color, ambient));
}

static t_color	calc_diffuse_color(\
	t_hit const *hit, t_point_light const *light)
{
	float	dot;
	t_color	diffuse;

	dot = vec3_dot(hit->normal, \
						vec3_normalize(vec3_sub(light->pos, hit->point)));
	if (dot <= 0.0)
		return ((t_color){.r = 0.0, .g = 0.0, .b = 0.0});
	diffuse = scale_color(dot, light->radiance);
	return (mul_color(hit->color, diffuse));
}

static t_color	calc_specular_color(\
	t_ray const *ray, t_hit const *hit, t_point_light const *light)
{
	t_vec3	from_light;
	t_vec3	reflection;
	float	dot;
	t_color	specular;

	from_light = vec3_normalize(vec3_sub(light->pos, hit->point));
	if (vec3_dot(hit->normal, from_light) <= 0.0)
		return ((t_color){.r = 0.0, .g = 0.0, .b = 0.0});
	reflection = vec3_normalize(vec3_sub(\
					vec3_scale(2 * vec3_dot(from_light, hit->normal), \
						hit->normal), from_light));
	dot = vec3_dot(vec3_scale(-1, ray->dir), reflection);
	if (dot <= 0.0)
		return ((t_color){.r = 0.0, .g = 0.0, .b = 0.0});
	specular = scale_color(powf(dot, SHININESS), light->radiance);
	return (specular);
}
