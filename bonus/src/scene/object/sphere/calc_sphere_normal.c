/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_sphere_normal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 19:29:16 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/12 22:52:52 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "object.h"
#include "ray.h"

t_vec3	calc_sphere_normal(\
	t_sphere const *sphere, t_ray const *ray, t_vec3 point)
{
	t_vec3	normal;

	normal = vec3_normalize(vec3_sub(point, sphere->center));
	if (vec3_dot(normal, ray->dir) > 0.0f)
		return (vec3_scale(-1.0f, normal));
	return (normal);
}
