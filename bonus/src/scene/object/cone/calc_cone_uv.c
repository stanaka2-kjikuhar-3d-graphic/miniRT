/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_cone_uv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 21:37:42 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/01 19:40:58 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

#include "../object_private.h"

t_vec2	calc_cone_uv(t_cone const *cone, t_vec3 point)
{
	t_quadric	quad;

	cone_to_quadric(cone, &quad);
	return (calc_quadric_uv(&quad, &cone->onb, point));
}
