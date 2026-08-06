/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_transform_point.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 22:54:07 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/08/06 22:15:50 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

/* Point (w = 1): projected back with the w division. See docs/matrix.md. */
t_vec3	mat4_transform_point(t_mat4 const *m, t_vec3 p)
{
	return (vec4_to_vec3(mat4_mul_vec4(m, vec4_from_point(p))));
}
