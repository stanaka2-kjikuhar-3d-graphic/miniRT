/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_uv_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 03:10:00 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/13 17:09:07 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "vector.h"

void	set_uv_checker(t_uv *uv, t_ivec2 checker_count)
{
	uv->checker_count = checker_count;
	uv->checker_size = (t_vec2){\
		.u = 1.0f / (float)checker_count.u, \
		.v = 1.0f / (float)checker_count.v};
}
