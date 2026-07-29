/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_transpose.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 22:22:30 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/07/22 22:40:28 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_mat4	mat4_transpose(t_mat4 m)
{
	t_mat4	result;
	int		row;
	int		col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			result.m[row][col] = m.m[col][row];
			++col;
		}
		++row;
	}
	return (result);
}
