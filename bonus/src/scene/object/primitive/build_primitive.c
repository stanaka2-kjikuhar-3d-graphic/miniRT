/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_primitive.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 01:12:33 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/08/07 01:29:40 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "ft_error.h"
#include "matrix.h"
#include "object.h"

#include "../object_private.h"

/*
        frame                          t_primitive
    +-------------+                +-----------------+
    | basis  (R)  |                | to_world  = M   |
    | origin (T)  |  ---- M --->   | to_local  = M^-1|
    | scale  (S)  |                | z_range         |
    +-------------+                +-----------------+

  false when a scale component is too small to invert.
*/
bool	build_primitive(t_primitive_frame const *frame, t_primitive *out)
{
	if (!mat4_is_valid_scale(frame->scale))
	{
		print_error(ERROR_DEGENERATE_SCALE);
		return (false);
	}
	out->type = frame->type;
	out->to_world = mat4_local_to_world(\
			&(frame->basis), frame->origin, frame->scale);
	out->to_local = mat4_inverse(&(out->to_world));
	out->z_range = frame->z_range;
	return (true);
}
