/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_object_uv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 19:39:56 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/26 21:43:27 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "vector.h"

#include "./surface_private.h"

t_vec2	calc_object_uv(t_object const *object, t_vec3 point)
{
	t_vec2	uv;

	uv = calc_primitive_uv(&(object->primitive), point, &(object->uv_info));
	return (adjust_uv_range(uv, \
			object->uv_info.layout.u_range, object->uv_info.layout.v_range));
}
