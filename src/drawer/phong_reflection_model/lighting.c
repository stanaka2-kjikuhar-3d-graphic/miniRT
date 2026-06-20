/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 00:45:12 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/20 17:24:41 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stddef.h>

#include "config.h"
#include "color.h"
#include "ray.h"
#include "light.h"

#include "./phong_reflection_model_private.h"

t_color	calc_ambient_color(\
			t_hit const *hit, t_ambient_lighting const *ambient_lighting);
t_color	calc_diffuse_color(t_hit const *hit, t_light const *light);
t_color	calc_specular_color(\
			t_ray const *ray, t_hit const *hit, t_light const *light);

t_color	lighting(t_ray const *ray, t_hit const *hit)
{
	t_color			color;
	t_light const	*light;

	color = calc_ambient_color(hit, get_ambient_lighting());
	light = NULL;
	while (get_next_light(&light))
	{
		if (!shadowing(hit, light))
		{
			color = add_color(color, calc_diffuse_color(hit, light));
			color = add_color(color, calc_specular_color(ray, hit, light));
		}
	}
	return (color);
}

t_color	calc_ambient_color(\
	t_hit const *hit, t_ambient_lighting const *ambient_lighting)
{
	t_color	ambient;

	ambient = scale_color(K_AMBIENT * I_AMBIENT, ambient_lighting->radiance);
	return (mul_color(hit->color, ambient));
}

t_color	calc_diffuse_color(t_hit const *hit, t_light const *light)
{
	double	dot;
	t_color	diffuse;

	dot = dvec3_dot(hit->normal, \
						dvec3_normalize(dvec3_sub(light->pos, hit->point)));
	if (dot <= 0.0)
		return ((t_color){.r = 0.0, .g = 0.0, .b = 0.0});
	diffuse = scale_color(K_DIFFUSE * dot * I_DIFFUSE, light->radiance);
	return (mul_color(hit->color, diffuse));
}

t_color	calc_specular_color(\
	t_ray const *ray, t_hit const *hit, t_light const *light)
{
	t_dvec3	from_light;
	t_dvec3	reflection;
	double	dot;
	t_color	specular;

	from_light = dvec3_normalize(dvec3_sub(light->pos, hit->point));
	if (dvec3_dot(hit->normal, from_light) <= 0.0)
		return ((t_color){.r = 0.0, .g = 0.0, .b = 0.0});
	reflection = dvec3_normalize(dvec3_sub(\
					dvec3_scale(2 * dvec3_dot(from_light, hit->normal), \
						hit->normal), from_light));
	dot = dvec3_dot(dvec3_scale(-1, ray->dir), reflection);
	if (dot <= 0.0)
		return ((t_color){.r = 0.0, .g = 0.0, .b = 0.0});
	specular = scale_color(K_SPECULAR * pow(dot, SHININESS) * I_SPECULAR, \
				light->radiance);
	return (specular);
}
