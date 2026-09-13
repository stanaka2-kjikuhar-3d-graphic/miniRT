/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_ray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 20:37:01 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/13 14:32:41 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "matrix.h"

t_ray	transform_ray(t_mat4 const *transform, t_ray const *ray)
{
	return ((t_ray){\
		.origin = mat4_transform_point(transform, ray->origin), \
		.dir = mat4_transform_dir(transform, ray->dir) \
	});
}
