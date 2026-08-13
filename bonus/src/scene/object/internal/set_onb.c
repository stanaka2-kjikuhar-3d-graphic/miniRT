/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_onb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 18:23:25 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/14 01:24:56 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "vector.h"
#include "object.h"

/*
branchless onb
https://jcgt.org/published/0006/01/01/paper-lowres.pdf
*/
void	set_onb(t_vec3 n, t_onb *onb)
{
	float const	sign = copysignf(1.0f, n.z);
	float const	inv_denom = 1.0f / (sign + n.z);
	float const	xx = n.x * n.x * inv_denom;
	float const	xy = n.x * n.y * inv_denom;
	float const	yy = n.y * n.y * inv_denom;

	onb->w = n;
	onb->u = vec3(1.0f - sign * xx, sign * -xy, -sign * n.x);
	onb->v = vec3(-xy, sign - yy, -n.y);
}
