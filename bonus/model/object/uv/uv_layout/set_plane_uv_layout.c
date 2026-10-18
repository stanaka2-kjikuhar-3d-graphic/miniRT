/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_plane_uv_layout.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 07:09:31 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/18 10:00:24 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "range.h"

#include "./uv_layout_private.h"

void	set_plane_uv_layout(t_object_id id, enum e_uv_type type)
{
	t_uv_layout	layout;

	layout.type = type;
	layout.aspect = 1.0f;
	layout.u_range = (t_range){.min = 0.0f, .max = 1.0f};
	layout.v_range = (t_range){.min = 0.0f, .max = 1.0f};
	set_uv_layout(id, &layout);
}
