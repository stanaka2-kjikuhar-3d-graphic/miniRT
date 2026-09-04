/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_specular_dot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 20:45:00 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/08/06 20:47:26 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

#include "config.h"
#include "ray.h"

#include "../phong_private.h"

static float	calc_phong_specular_dot(t_ray const *ray, \
					t_hit const *hit, t_vec3 to_light);
static float	calc_blinn_phong_specular_dot(t_ray const *ray, \
					t_hit const *hit, t_vec3 to_light);

float	calc_specular_dot(t_ray const *ray, t_hit const *hit, t_vec3 to_light)
{
	if (RENDERING_MODEL == BLINN_PHONG_MODEL)
		return (calc_blinn_phong_specular_dot(ray, hit, to_light));
	return (calc_phong_specular_dot(ray, hit, to_light));
}

static float	calc_phong_specular_dot(t_ray const *ray, \
	t_hit const *hit, t_vec3 to_light)
{
	t_vec3	reflection;

	reflection = vec3_normalize(vec3_sub(\
					vec3_scale(2 * vec3_dot(to_light, hit->normal), \
						hit->normal), to_light));
	return (vec3_dot(vec3_scale(-1.0f, ray->dir), reflection));
}

static float	calc_blinn_phong_specular_dot(t_ray const *ray, \
	t_hit const *hit, t_vec3 to_light)
{
	t_vec3	halfway;

	halfway = vec3_normalize(vec3_add(vec3_scale(-1.0f, ray->dir), to_light));
	return (vec3_dot(hit->normal, halfway));
}
