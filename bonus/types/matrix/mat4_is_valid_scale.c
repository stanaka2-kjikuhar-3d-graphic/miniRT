/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_is_valid_scale.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 00:32:10 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/10/26 21:39:24 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>

#include "config.h"
#include "vector.h"
#include "matrix.h"

/*
scale near 0  ->  M is singular  ->  mat4_inverse(M) blows up

    |s| <  EPSILON   reject
    |s| >= EPSILON   accept

  a negative scale is accepted (it only mirrors the axis).
*/
bool	mat4_is_valid_scale(t_vec3 scale)
{
	return (EPSILON <= fabsf(scale.x) \
		&& EPSILON <= fabsf(scale.y) \
		&& EPSILON <= fabsf(scale.z));
}
