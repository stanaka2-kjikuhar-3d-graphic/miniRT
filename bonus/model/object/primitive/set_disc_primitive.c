/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_disc_primitive.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 21:29:56 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/17 01:15:46 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "vector.h"
#include "primitive.h"
#include "object.h"
#include "id.h"

#include "./object_primitive_private.h"

bool	set_disc_primitive(t_id object_id, t_disc const *disc)
{
	t_primitive_frame	frame;
	t_primitive			prim;

	frame.type = UNIT_DISC;
	frame.basis = mat3_build_onb(disc->normal);
	frame.origin = disc->center;
	frame.scale = vec3(disc->radius, disc->radius, 1.0f);
	if (!build_primitive(&frame, &prim))
		return (false);
	set_primitive(object_id, &prim);
	return (true);
}
