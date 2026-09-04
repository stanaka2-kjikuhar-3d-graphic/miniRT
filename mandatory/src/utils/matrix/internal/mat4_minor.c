/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_minor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 23:11:09 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/08/06 22:20:18 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

/* 3x3 determinant of m with `row` and `col` removed. */
float	mat4_minor(t_mat4 const *m, int row, int col)
{
	float	sub[3][3];
	int		i;
	int		j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			sub[i][j] = m->m[i + (i >= row)][j + (j >= col)];
			++j;
		}
		++i;
	}
	return (sub[0][0] * (sub[1][1] * sub[2][2] - sub[1][2] * sub[2][1])
		- sub[0][1] * (sub[1][0] * sub[2][2] - sub[1][2] * sub[2][0])
		+ sub[0][2] * (sub[1][0] * sub[2][1] - sub[1][1] * sub[2][0]));
}
