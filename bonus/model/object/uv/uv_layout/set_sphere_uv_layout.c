/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sphere_uv_layout.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 07:09:48 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/08 22:27:32 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "object.h"
#include "range.h"

#include "./uv_layout_private.h"

void	set_sphere_uv_layout(size_t id, enum e_uv_type type)
{
	t_uv_layout	layout;

	layout.type = type;
	layout.aspect = 2.0f;
	layout.u_range = (t_range){.min = 0.0f, .max = 1.0f};
	layout.v_range = (t_range){.min = 0.0f, .max = 1.0f};
	set_uv_layout(id, &layout);
}
