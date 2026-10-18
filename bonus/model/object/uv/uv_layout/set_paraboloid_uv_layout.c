/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_paraboloid_uv_layout.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 07:09:15 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/18 08:57:02 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <math.h>

#include "object.h"
#include "range.h"
#include "id.h"

#include "./uv_layout_private.h"

void	set_paraboloid_uv_layout(\
	t_id id, enum e_uv_type type, t_paraboloid const *paraboloid)
{
	t_uv_layout	layout;
	float		top_radius;

	layout.type = type;
	top_radius = sqrtf(paraboloid->quadratic_coefficient * paraboloid->height);
	layout.aspect = (float)(2.0f * M_PI * top_radius) / paraboloid->height;
	layout.u_range = (t_range){.min = 0.0f, .max = 1.0f};
	layout.v_range = (t_range){.min = 0.0f, .max = 1.0f};
	set_uv_layout(id, &layout);
}
