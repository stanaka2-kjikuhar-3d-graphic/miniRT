/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_basis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 22:54:50 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/08/06 22:15:32 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

/* local->world M: upper 3x3 = basis, 4th column = origin. */
t_mat4	mat4_basis(t_mat3 const *basis, t_vec3 origin)
{
	t_mat4	result;
	int		row;
	int		col;

	result = mat4_identity();
	row = 0;
	while (row < 3)
	{
		col = 0;
		while (col < 3)
		{
			result.m[row][col] = basis->m[row][col];
			++col;
		}
		++row;
	}
	result.m[0][3] = origin.x;
	result.m[1][3] = origin.y;
	result.m[2][3] = origin.z;
	return (result);
}
