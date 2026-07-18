/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_uv_range.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 21:55:09 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/05 22:04:54 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "vector.h"

t_vec2	adjust_uv_range(t_vec2 uv, t_range u_range, t_range v_range)
{
	float	u_size;
	float	v_size;

	u_size = u_range.max - u_range.min;
	v_size = v_range.max - v_range.min;
	return ((t_vec2){\
		.u = uv.u * u_size + u_range.min, \
		.v = uv.v * v_size + v_range.min \
	});
}
