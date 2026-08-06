/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_mul.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 22:27:41 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/08/06 22:15:46 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

/* result = a * b (result[row][col] = sum_k a[row][k] * b[k][col]) */
t_mat4	mat4_mul(t_mat4 const *a, t_mat4 const *b)
{
	t_mat4	result;
	int		row;
	int		col;
	int		k;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			result.m[row][col] = 0.0f;
			k = 0;
			while (k < 4)
			{
				result.m[row][col] += a->m[row][k] * b->m[k][col];
				++k;
			}
			++col;
		}
		++row;
	}
	return (result);
}
