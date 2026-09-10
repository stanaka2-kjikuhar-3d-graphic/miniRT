/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 16:41:09 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/09/10 23:23:45 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "config.h"
#include "color.h"
#include "vector.h"
#include "ray.h"

#include "intersection.h"
#include "phong.h"
#include "./raytracer_private.h"

static t_ray	calc_reflect_ray(t_ray const *ray, t_hit const *hit);

t_color	trace_ray(t_ray ray, int depth)
{
	t_hit	hit;
	t_color	local;
	t_color	reflected;

	hit = find_closest_hit(&ray);
	if (hit.object == NULL)
		return ((t_color){.r = 0.0f, .g = 0.0f, .b = 0.0f});
	local = phong_lighting(&ray, &hit);
	if (depth >= MAX_RECURSION_DEPTH \
		|| hit.object->material.reflectivity <= 0.0f)
		return (local);
	reflected = trace_ray(calc_reflect_ray(&ray, &hit), depth + 1);
	return (add_color(\
		scale_color(1.0f - hit.object->material.reflectivity, local), \
		scale_color(hit.object->material.reflectivity, reflected)));
}

static t_ray	calc_reflect_ray(t_ray const *ray, t_hit const *hit)
{
	t_ray	reflect_ray;
	float	offset;

	reflect_ray.dir = vec3_sub(ray->dir, \
		vec3_scale(2.0f * vec3_dot(ray->dir, hit->normal), hit->normal));
	offset = SHADOW_EPSILON * fmaxf(1.0f, vec3_length(hit->point));
	reflect_ray.origin = vec3_add(hit->point, \
		vec3_scale(offset, hit->normal));
	return (reflect_ray);
}
