/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_hyperboloid_uv.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 21:37:42 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/22 21:53:40 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "vector.h"
#include "object.h"

// TODO: implement hyperboloid uv
t_vec2	calc_hyperboloid_uv(t_hyperboloid const *hyperboloid, t_vec3 point)
{
	(void)hyperboloid;
	(void)point;
	return ((t_vec2){.u = 0.0f, .v = 0.0f});
}
