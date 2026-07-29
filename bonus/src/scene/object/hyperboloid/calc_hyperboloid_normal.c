/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_hyperboloid_normal.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 19:25:57 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/22 21:53:46 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "object.h"
#include "ray.h"

#include "../object_private.h"

// TODO: implement hyperboloid normal
t_vec3	calc_hyperboloid_normal(\
	t_hyperboloid const *hyperboloid, t_ray const *ray, t_vec3 point)
{
	(void)hyperboloid;
	(void)ray;
	(void)point;
	return ((t_vec3){.x = 0.0f, .y = 0.0f, .z = 0.0f});
}
