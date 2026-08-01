/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_hyperboloid_uv.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 01:36:22 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/01 20:45:41 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

#include "../object_private.h"

t_vec2	calc_hyperboloid_uv(t_hyperboloid const *hyperboloid, t_vec3 point)
{
	t_quadric	quad;
	t_vec2		uv;

	hyperboloid_to_quadric(hyperboloid, &quad);
	uv = calc_quadric_uv(&quad, &hyperboloid->onb, point);
	uv.v = 1.0f - uv.v;
	return (uv);
}
