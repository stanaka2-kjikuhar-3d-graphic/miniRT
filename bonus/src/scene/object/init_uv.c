/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_uv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 01:11:01 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/12 01:22:13 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "object.h"

void	init_uv(t_uv *uv, enum e_object_type object_type)
{
	uv->type = UV_PLANE;
	uv->pattern_size = 10.0f;
	uv->u_per_v = 1.0f;
	uv->u_range = (t_range){.min = 0.0f, .max = 1.0f};
	uv->v_range = (t_range){.min = 0.0f, .max = 1.0f};
}
