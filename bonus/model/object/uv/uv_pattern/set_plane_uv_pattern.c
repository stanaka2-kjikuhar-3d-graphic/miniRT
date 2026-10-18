/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_plane_uv_pattern.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 21:10:23 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/18 10:01:15 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "vector.h"

#include "./uv_pattern_private.h"

void	set_plane_uv_pattern(\
	t_object_id id, float pattern_size, t_vec2 half_size)
{
	t_uv_pattern	pattern;

	pattern.size = pattern_size;
	if (isfinite(half_size.x) \
		&& isfinite(half_size.y))
	{
		pattern.scale.u \
			= half_size.x / pattern_size;
		pattern.scale.v \
			= half_size.y / pattern_size;
	}
	else
	{
		pattern.scale.u = 1.0f / pattern_size;
		pattern.scale.v = 1.0f / pattern_size;
	}
	set_uv_pattern(id, &pattern);
}
