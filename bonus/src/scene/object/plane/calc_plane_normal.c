/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_plane_normal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 19:28:20 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/12 23:21:34 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "object.h"
#include "ray.h"

t_vec3	calc_plane_normal(t_plane const *plane, t_ray const *ray)
{
	if (vec3_dot(plane->normal, ray->dir) > 0.0f)
		return (vec3_scale(-1.0f, plane->normal));
	return (plane->normal);
}
