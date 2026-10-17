/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cone_uv_layout.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 07:08:07 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/17 17:00:24 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <math.h>

#include "object.h"
#include "range.h"
#include "id.h"

#include "./uv_layout_private.h"

void	set_cone_uv_layout(\
	t_id object_id, enum e_uv_type type, t_cone const *cone)
{
	t_uv_layout	layout;
	float		generatrix;
	float		cap_ratio;

	generatrix \
		= sqrtf(cone->radius * cone->radius + cone->height * cone->height);
	layout.type = type;
	layout.aspect = (float)(\
		2.0f * M_PI * cone->radius) / (cone->radius + generatrix);
	cap_ratio = cone->radius / (2.0f * (cone->radius + generatrix));
	layout.u_range = (t_range){.min = 0.0f, .max = 1.0f};
	layout.v_range = (t_range){.min = 0.0f, .max = 1.0f - cap_ratio};
	set_uv_layout(object_id, &layout);
}
