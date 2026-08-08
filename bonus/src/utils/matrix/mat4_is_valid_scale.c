/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_is_valid_scale.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 00:32:10 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/08/07 01:05:02 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "config.h"
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
