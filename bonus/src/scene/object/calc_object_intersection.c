/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_object_intersection.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 00:50:10 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/16 17:39:05 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "ray.h"

#include "./object_private.h"

float	calc_object_intersection(t_object const *object, t_ray const *ray)
{
	return (calc_primitive_intersection(&(object->primitive), ray));
}
