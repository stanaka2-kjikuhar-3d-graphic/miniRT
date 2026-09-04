/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_transform_dir.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 22:54:14 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/08/06 22:15:48 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

/* Direction (w = 0): no translation, not normalized. See docs/matrix.md. */
t_vec3	mat4_transform_dir(t_mat4 const *m, t_vec3 v)
{
	return (vec4_to_vec3(mat4_mul_vec4(m, vec4_from_dir(v))));
}
