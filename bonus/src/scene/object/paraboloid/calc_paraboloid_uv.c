/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_paraboloid_uv.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 00:55:13 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/06 21:33:45 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

#include "../object_private.h"

t_vec2	calc_paraboloid_uv(t_paraboloid const *paraboloid, t_vec3 point)
{
	return (calc_quadric_uv(&(paraboloid->quadric), &paraboloid->onb, point));
}
