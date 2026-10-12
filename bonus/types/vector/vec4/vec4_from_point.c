/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_from_point.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 17:44:39 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/07/19 18:14:37 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/* Point (w = 1): affected by translation. See docs/matrix.md. */
t_vec4	vec4_from_point(t_vec3 v)
{
	return ((t_vec4){.x = v.x, .y = v.y, .z = v.z, .w = 1.0f});
}
