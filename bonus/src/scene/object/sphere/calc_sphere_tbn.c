/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_sphere_tbn.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 19:54:35 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/01 16:29:50 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "config.h"
#include "object.h"
#include "vector.h"

t_onb	calc_sphere_tbn(t_sphere const *sphere, t_vec3 normal)
{
	t_onb	tbn;
	float	tu;
	float	tv;
	float	len;

	tbn.w = normal;
	tu = vec3_dot(normal, sphere->onb.u);
	tv = vec3_dot(normal, sphere->onb.v);
	len = sqrtf(tu * tu + tv * tv);
	if (len < EPSILON)
		return (sphere->onb);
	tbn.u = vec3_div(len, vec3_sub(\
				vec3_scale(tu, sphere->onb.v), vec3_scale(tv, sphere->onb.u)));
	tbn.v = vec3_cross(tbn.u, tbn.w);
	return (tbn);
}
