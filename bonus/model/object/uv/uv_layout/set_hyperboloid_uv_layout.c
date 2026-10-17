/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hyperboloid_uv_layout.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 07:08:57 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/17 01:15:46 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <math.h>

#include "object.h"
#include "range.h"
#include "id.h"

#include "./uv_layout_private.h"

void	set_hyperboloid_uv_layout(\
	t_id object_id, enum e_uv_type type, t_hyperboloid const *hyperboloid)
{
	t_uv_layout	layout;
	float		cap_ratio;

	layout.type = type;
	layout.aspect = (float)(2.0f * M_PI * hyperboloid->cap_radius) \
				/ (2.0f * (hyperboloid->cap_radius + hyperboloid->half_height));
	cap_ratio = hyperboloid->cap_radius \
				/ (2.0f * (hyperboloid->cap_radius + hyperboloid->half_height));
	layout.u_range = (t_range){.min = 0.0f, .max = 1.0f};
	layout.v_range = (t_range){.min = cap_ratio, .max = 1.0f - cap_ratio};
	set_uv_layout(object_id, &layout);
}
