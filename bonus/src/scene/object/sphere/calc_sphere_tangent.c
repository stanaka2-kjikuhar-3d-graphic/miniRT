/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_sphere_tangent.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 19:54:35 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/20 22:58:43 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "config.h"
#include "object.h"
#include "vector.h"

t_vec3	calc_sphere_tangent(t_sphere const *sphere, t_vec3 normal)
{
	double	tu;
	double	tv;
	double	len;

	tu = vec3_dot(normal, sphere->onb.u);
	tv = vec3_dot(normal, sphere->onb.v);
	len = sqrt(tu * tu + tv * tv);
	if (len < EPSILON)
		return (sphere->onb.u);
	return (vec3_scale((float)(1.0 / len)), vec3_sub(\
		vec3_scale(tv, sphere->onb.v), vec3_scale(tu, sphere->onb.u) \
	));
}
