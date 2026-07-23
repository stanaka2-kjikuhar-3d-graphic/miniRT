/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_cone_normal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 19:25:57 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/22 22:03:22 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "object.h"
#include "ray.h"

#include "../object_private.h"

// TODO: implement cone normal
t_vec3	calc_cone_normal(\
	t_cone const *cone, t_ray const *ray, t_vec3 point)
{
	(void)cone;
	(void)ray;
	(void)point;
	return ((t_vec3){.x = 0.0f, .y = 0.0f, .z = 0.0f});
}
