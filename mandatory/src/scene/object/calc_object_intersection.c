/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_object_intersection.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 00:50:10 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/29 17:41:14 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "ray.h"

#include "./object_private.h"

float	calc_object_intersection(t_object const *object, t_ray const *ray)
{
	return (calc_primitive_intersection(&(object->primitive), ray));
}
