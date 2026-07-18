/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_circle_normal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 19:27:11 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/12 23:20:59 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "object.h"
#include "ray.h"

t_vec3	calc_circle_normal(t_circle const *circle, t_ray const *ray)
{
	if (vec3_dot(circle->normal, ray->dir) > 0.0f)
		return (vec3_scale(-1.0f, circle->normal));
	return (circle->normal);
}
