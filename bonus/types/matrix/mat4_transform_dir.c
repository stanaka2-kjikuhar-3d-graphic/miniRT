/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_transform_dir.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 22:54:14 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/10/26 21:39:48 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "matrix.h"

/* Direction (w = 0): no translation, not normalized. See docs/matrix.md. */
t_vec3	mat4_transform_dir(t_mat4 const *m, t_vec3 v)
{
	return (vec4_to_vec3(mat4_mul_vec4(m, vec4_from_dir(v))));
}
