/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_circle_tbn.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 20:28:05 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/21 22:33:11 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "vector.h"

t_onb	calc_circle_tbn(t_circle const *circle, t_vec3 point, \
	t_vec3 normal, enum e_uv_type uv_type)
{
	t_onb	tbn;

	tbn.w = normal;
	tbn.v = vec3_normalize(vec3_sub(point, circle->center));
	if (uv_type == UV_LOWER_CAP)
		tbn.v = vec3_scale(-1.0f, tbn.v);
	tbn.u = vec3_cross(tbn.w, tbn.v);
	return (tbn);
}
