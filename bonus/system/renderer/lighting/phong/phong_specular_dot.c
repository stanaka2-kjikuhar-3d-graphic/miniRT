/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_specular_dot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 20:45:00 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/10/31 21:03:38 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "vector.h"

#include "renderer.h"
#include "../lighting_private.h"
#include "../../renderer_private.h"

static float	calc_phong_specular_dot(t_ray const *ray, \
					t_hit const *hit, t_vec3 to_light);
static float	calc_blinn_phong_specular_dot(t_ray const *ray, \
					t_hit const *hit, t_vec3 to_light);

float	calc_specular_dot(t_ray const *ray, t_hit const *hit, t_vec3 to_light)
{
	if (get_phong_mode() == PHONG_MODE_BLINN_PHONG)
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
