/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 22:03:03 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/10/26 21:45:02 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "vector.h"
#include "ray.h"

#include "./raytracer_private.h"
#include "../renderer_private.h"

static float	calc_ray_offset(t_hit const *hit);
static float	calc_eta_ratio(t_hit const *hit);

float	calc_sin2_transmitted(t_ray const *ray, t_hit const *hit)
{
	float	eta;
	float	cos_i;

	eta = calc_eta_ratio(hit);
	cos_i = -vec3_dot(ray->dir, hit->normal);
	return (eta * eta * (1.0f - cos_i * cos_i));
}

t_ray	calc_reflect_ray(t_ray const *ray, t_hit const *hit)
{
	t_ray	reflect_ray;

	reflect_ray.dir = vec3_sub(ray->dir, \
		vec3_scale(2.0f * vec3_dot(ray->dir, hit->normal), hit->normal));
	reflect_ray.origin = vec3_add(hit->point, \
		vec3_scale(calc_ray_offset(hit), hit->normal));
	return (reflect_ray);
}

t_ray	calc_refract_ray(t_ray const *ray, t_hit const *hit)
{
	t_ray	refract_ray;
	float	eta;
	float	cos_i;
	float	cos_t;

	eta = calc_eta_ratio(hit);
	cos_i = -vec3_dot(ray->dir, hit->normal);
	cos_t = sqrtf(fmaxf(0.0f, 1.0f - calc_sin2_transmitted(ray, hit)));
	refract_ray.dir = vec3_normalize(vec3_add(vec3_scale(eta, ray->dir), \
		vec3_scale(eta * cos_i - cos_t, hit->normal)));
	refract_ray.origin = vec3_sub(hit->point, \
		vec3_scale(calc_ray_offset(hit), hit->normal));
	return (refract_ray);
}

static float	calc_ray_offset(t_hit const *hit)
{
	return (SHADOW_EPSILON * fmaxf(1.0f, vec3_length(hit->point)));
}

static float	calc_eta_ratio(t_hit const *hit)
{
	float const	ior = hit->material->ior;

	if (hit->is_front_face)
		return (1.0f / ior);
	return (ior);
}
