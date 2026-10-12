/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_object_tbn.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 22:51:01 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/09 07:13:47 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "object.h"
#include "vector.h"

#include "./surface_private.h"

t_mat3	calc_object_tbn(t_object const *object, t_vec3 point, t_vec3 normal)
{
	return (calc_primitive_tbn(&(object->primitive), point, normal, \
			object->uv.layout.type));
}
