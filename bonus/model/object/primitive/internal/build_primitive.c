/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_primitive.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 01:12:33 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/10/26 21:09:21 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "logger.h"
#include "matrix.h"
#include "primitive.h"

#include "../object_primitive_private.h"

/*
        frame                          t_primitive
    +-------------+                +-----------------+
    | basis  (R)  |                | to_world  = M   |
    | origin (T)  |  ---- M --->   | to_local  = M^-1|
    | scale  (S)  |                | z_range         |
    | z_range     |                |   or half_size  |
    |   or        |                +-----------------+
    |   half_size |
    +-------------+

  z_range and half_size share a union, so only the member the type
  actually reads is written: half_size for INFINITE_PLANE, z_range for
  the quadrics. UNIT_PLANE and UNIT_DISC read neither.

  false when a scale component is too small to invert.
*/
bool	build_primitive(t_primitive_frame const *frame, t_primitive *result)
{
	if (!mat4_is_valid_scale(frame->scale))
	{
		print_log_msg(LOG_ERROR, ERROR_DEGENERATE_SCALE);
		return (false);
	}
	result->type = frame->type;
	result->to_world = mat4_local_to_world(\
			&(frame->basis), frame->origin, frame->scale);
	result->to_local = mat4_world_to_local(\
			&(frame->basis), frame->origin, frame->scale);
	if (frame->type == INFINITE_PLANE)
		result->half_size = frame->half_size;
	else if (is_quadric_primitive(frame->type))
		result->z_range = frame->z_range;
	return (true);
}
