/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_plane_normal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 19:28:20 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/19 19:28:36 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "object.h"
#include "ray.h"

t_dvec3	calc_plane_normal(t_plane const *plane, t_ray const *ray)
{
	if (dvec3_dot(plane->normal, ray->dir) > 0)
		return (dvec3_scale(-1, plane->normal));
	return (plane->normal);
}
