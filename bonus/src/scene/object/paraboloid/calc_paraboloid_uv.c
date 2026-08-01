/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_paraboloid_uv.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 00:55:13 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/01 19:40:58 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

#include "../object_private.h"

t_vec2	calc_paraboloid_uv(t_paraboloid const *paraboloid, t_vec3 point)
{
	t_quadric	quad;

	paraboloid_to_quadric(paraboloid, &quad);
	return (calc_quadric_uv(&quad, &paraboloid->onb, point));
}
