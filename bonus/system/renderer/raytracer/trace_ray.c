/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 16:41:09 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/10/26 21:49:24 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "color.h"
#include "ray.h"

#include "./raytracer_private.h"
#include "../renderer_private.h"

static t_color	calc_local(t_ray const *ray, t_hit const *hit, float weight);
static t_color	calc_reflected(t_ray const *ray, \
					t_hit const *hit, float weight, int depth);
static t_color	calc_refracted(t_ray const *ray, \
					t_hit const *hit, float weight, int depth);

t_color	trace_ray(t_ray ray, int depth)
{
	t_hit		hit;
	t_weights	weights;
	t_color		local;
	t_color		reflected;
	t_color		refracted;

	hit = find_closest_hit(&ray);
	if (hit.object == NULL)
		return ((t_color){.r = 0.0f, .g = 0.0f, .b = 0.0f});
	set_hit_record(&ray, &hit);
	weights = calc_weights(&ray, &hit, depth);
	local = calc_local(&ray, &hit, weights.local);
	reflected = calc_reflected(&ray, &hit, weights.reflected, depth);
	refracted = calc_refracted(&ray, &hit, weights.refracted, depth);
	return (add_color(add_color(local, reflected), refracted));
}

static t_color	calc_local(t_ray const *ray, t_hit const *hit, float weight)
{
	if (weight <= 0.0f)
		return ((t_color){.r = 0.0f, .g = 0.0f, .b = 0.0f});
	return (scale_color(weight, phong_lighting(ray, hit)));
}

static t_color	calc_reflected(t_ray const *ray, t_hit const *hit, \
	float weight, int depth)
{
	if (weight <= 0.0f)
		return ((t_color){.r = 0.0f, .g = 0.0f, .b = 0.0f});
	return (scale_color(weight, \
		trace_ray(calc_reflect_ray(ray, hit), depth + 1)));
}

static t_color	calc_refracted(t_ray const *ray, t_hit const *hit, \
	float weight, int depth)
{
	if (weight <= 0.0f)
		return ((t_color){.r = 0.0f, .g = 0.0f, .b = 0.0f});
	return (scale_color(weight, \
		trace_ray(calc_refract_ray(ray, hit), depth + 1)));
}
