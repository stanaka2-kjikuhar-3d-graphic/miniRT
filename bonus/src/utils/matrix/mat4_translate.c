/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_translate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 22:54:24 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/07/22 23:29:57 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_mat4	mat4_translate(t_vec3 t)
{
	t_mat4	result;

	result = mat4_identity();
	result.m[0][3] = t.x;
	result.m[1][3] = t.y;
	result.m[2][3] = t.z;
	return (result);
}
