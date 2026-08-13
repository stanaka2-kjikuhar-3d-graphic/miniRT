/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_aabb_centroid.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 00:00:48 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/14 00:20:15 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "vector.h"

t_vec3	calc_aabb_centroid(t_aabb const *aabb)
{
	return (vec3(\
		(aabb->x.min + aabb->x.max) / 2.0f, \
		(aabb->y.min + aabb->y.max) / 2.0f, \
		(aabb->z.min + aabb->z.max) / 2.0f\
	));
}


