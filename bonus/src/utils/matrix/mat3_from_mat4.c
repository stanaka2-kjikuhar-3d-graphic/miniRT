/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat3_from_mat4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 23:11:02 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/08/06 22:15:29 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

/* Upper-left 3x3 (linear part) for normal transforms. */
t_mat3	mat3_from_mat4(t_mat4 const *m)
{
	t_mat3	result;
	int		row;
	int		col;

	row = 0;
	while (row < 3)
	{
		col = 0;
		while (col < 3)
		{
			result.m[row][col] = m->m[row][col];
			++col;
		}
		++row;
	}
	return (result);
}
