/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_sphere_normal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 19:29:16 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/19 19:29:48 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "object.h"
#include "ray.h"

t_dvec3	calc_sphere_normal(\
	t_sphere const *sphere, t_ray const *ray, t_dvec3 point)
{
	t_dvec3	normal;

	normal = dvec3_normalize(dvec3_sub(point, sphere->center));
	if (dvec3_dot(normal, ray->dir) > 0)
		return (dvec3_scale(-1, normal));
	return (normal);
}
