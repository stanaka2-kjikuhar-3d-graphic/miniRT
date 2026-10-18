/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_uv_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 03:10:00 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/18 08:57:02 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "object.h"
#include "vector.h"
#include "id.h"

#include "../../object_private.h"

void	set_uv_checker(t_id id, t_ivec2 checker_count)
{
	t_uv_checker	checker;
	t_object		*object;

	checker.count = checker_count;
	checker.size = (t_vec2){\
		.u = 1.0f / (float)checker_count.u, \
		.v = 1.0f / (float)checker_count.v};
	object = get_mutable_object(id);
	object->uv.checker = checker;
}
