/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_closest_hit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 22:46:14 by stanaka2          #+#    #+#             */
/*   Updated: 2026/11/06 06:26:19 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stddef.h>
#include <stdbool.h>

#include "ray.h"
#include "vector.h"

#include "./intersection_private.h"
#include "../renderer_private.h"

#define CORRECT_EPSILON 0.0001f // 1e-4

static void	correct_hit_point(t_hit *hit, t_vec3 dir);
static bool	is_valid_correction(float t, float max_correct);

t_hit	find_closest_hit(t_ray const *ray)
{
	t_hit	hit;

	hit = (t_hit){.object = NULL, .t = INFINITY};
	flat_list_intersection(&hit, ray);
	bvh_intersection(&hit, ray);
	if (hit.object != NULL)
	{
		hit.point = vec3_add(ray->origin, vec3_scale(hit.t, ray->dir));
		correct_hit_point(&hit, ray->dir);
	}
	return (hit);
}

static void	correct_hit_point(t_hit *hit, t_vec3 dir)
{
	t_ray	ray;
	float	t0;
	float	t1;
	float	max_correct;

	max_correct = CORRECT_EPSILON * (1.0f + hit->t);
	ray.origin = hit->point;
	ray.dir = dir;
	t0 = calc_object_intersection(hit->object, &ray);
	ray.dir = vec3_scale(-1.0f, dir);
	t1 = calc_object_intersection(hit->object, &ray);
	if (is_valid_correction(t0, max_correct)
		&& (!is_valid_correction(t1, max_correct) || fabsf(t0) < fabsf(t1)))
		hit->point = vec3_add(hit->point, vec3_scale(t0, dir));
	else if (is_valid_correction(t1, max_correct))
		hit->point = vec3_add(hit->point, vec3_scale(t1, ray.dir));
}

static bool	is_valid_correction(float t, float max_correct)
{
	return (isfinite(t) && fabsf(t) <= max_correct);
}
