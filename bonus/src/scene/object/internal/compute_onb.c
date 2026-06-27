/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_onb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 18:23:25 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/25 21:46:37 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "vector.h"

/*
branchness onb
https://jcgt.org/published/0006/01/01/paper-lowres.pdf
*/
void	compute_onb(t_vec3 n, t_vec3 *tangent, t_vec3 *bitangent)
{
	float const	sign = copysignf(1.0f, n.z);
	float const	inv_denom = 1.0f / (sign + n.z);
	float const xx = n.x * n.x * inv_denom;
	float const	xy = n.x * n.y * inv_denom;
	float const yy = n.y * n.y * inv_denom;

	*tangent = vec3(1.0f - sign * xx, sign * -xy, -sign * n.x);
	*bitangent = vec3(-xy, sign - yy, -n.y);
}
