/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_object_normal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 00:51:51 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/16 19:06:44 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "object.h"
#include "ray.h"

#include "./object_private.h"

t_vec3	calc_object_normal(\
	t_object const *object, t_ray const *ray, t_vec3 point)
{
	return (calc_primitive_normal(&(object->primitive), ray, point));
}
