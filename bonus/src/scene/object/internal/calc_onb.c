/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_onb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 18:23:25 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/17 22:55:41 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "matrix.h"
#include "vector.h"

/*
branchless onb
https://jcgt.org/published/0006/01/01/paper-lowres.pdf
*/
t_mat3	calc_onb(t_vec3 n)
{
	float const	sign = copysignf(1.0f, n.z);
	float const	inv_denom = 1.0f / (sign + n.z);
	float const	xx = n.x * n.x * inv_denom;
	float const	xy = n.x * n.y * inv_denom;
	float const	yy = n.y * n.y * inv_denom;

	return ((t_mat3){.m = {\
		{1.0f - sign * xx, -xy, n.x}, \
		{sign * -xy, sign - yy, n.y}, \
		{-sign * n.x, -n.y, n.z} \
	}});
}
