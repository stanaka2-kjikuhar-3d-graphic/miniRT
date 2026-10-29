/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_disc_primitive.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 21:29:56 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/18 09:59:06 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "vector.h"
#include "primitive.h"
#include "object.h"

#include "./object_primitive_private.h"

bool	set_disc_primitive(t_object_id id, t_disc const *disc)
{
	t_primitive_frame	frame;
	t_primitive			prim;

	frame.type = UNIT_DISC;
	frame.basis = mat3_build_onb(disc->normal);
	frame.origin = disc->center;
	frame.scale = vec3(disc->radius, disc->radius, 1.0f);
	if (!build_primitive(&frame, &prim))
		return (false);
	set_primitive(id, &prim);
	return (true);
}
