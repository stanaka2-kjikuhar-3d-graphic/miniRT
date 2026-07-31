/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadric_in_bounds.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 17:29:04 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/07/31 17:29:04 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "vector.h"
#include "object.h"

/* Axis-height clamp for finite quadrics. See docs/quadric.md. */
bool	quadric_in_bounds(t_quadric const *q, t_vec3 point)
{
	float	h;

	if (!q->finite)
		return (true);
	h = vec3_dot(vec3_sub(point, q->center), q->axis);
	return (q->h_min <= h && h <= q->h_max);
}
