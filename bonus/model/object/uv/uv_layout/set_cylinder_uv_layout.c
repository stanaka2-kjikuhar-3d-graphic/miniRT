/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cylinder_uv_layout.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 07:08:22 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/18 10:00:06 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "object.h"
#include "range.h"

#include "./uv_layout_private.h"

void	set_cylinder_uv_layout(\
	t_id id, enum e_uv_type type, t_cylinder const *cylinder)
{
	t_uv_layout	layout;
	float		cap_ratio;

	layout.type = type;
	layout.aspect = (float)(2.0f * M_PI * cylinder->radius) \
						/ (2.0f * (cylinder->radius + cylinder->half_height));
	cap_ratio = cylinder->radius \
					/ (2.0f * (cylinder->radius + cylinder->half_height));
	layout.u_range = (t_range){.min = 0.0f, .max = 1.0f};
	layout.v_range = (t_range){.min = cap_ratio, .max = 1.0f - cap_ratio};
	set_uv_layout(id, &layout);
}
