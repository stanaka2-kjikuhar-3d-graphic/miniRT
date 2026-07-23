/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_paraboloid_uv.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 21:37:42 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/22 21:58:18 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "vector.h"
#include "object.h"

// TODO: implement paraboloid uv
t_vec2	calc_paraboloid_uv(t_paraboloid const *paraboloid, t_vec3 point)
{
	(void)paraboloid;
	(void)point;
	return ((t_vec2){.u = 0.0f, .v = 0.0f});
}
