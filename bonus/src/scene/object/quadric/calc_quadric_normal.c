/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_quadric_normal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 17:33:18 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/08/06 22:21:08 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "matrix.h"
#include "object.h"
#include "ray.h"

t_vec3	calc_quadric_normal(\
	t_quadric const *q, t_ray const *ray, t_vec3 point)
{
	t_vec4	gradient;
	t_vec3	normal;

	gradient = mat4_mul_vec4(&(q->q), vec4_from_point(point));
	normal = vec3_normalize(vec3(gradient.x, gradient.y, gradient.z));
	if (vec3_dot(normal, ray->dir) > 0.0f)
		normal = vec3_scale(-1.0f, normal);
	return (normal);
}
