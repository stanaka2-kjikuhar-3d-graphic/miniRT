/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_inverse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 22:41:11 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/07/22 23:15:00 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

/* Inverse of m. The caller must pass an invertible matrix (det != 0). */
t_mat4	mat4_inverse(t_mat4 m)
{
	t_mat4	result;
	float	det;
	int		row;
	int		col;

	det = mat4_det(m);
	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			result.m[col][row] = mat4_cofactor(m, row, col) / det;
			++col;
		}
		++row;
	}
	return (result);
}
