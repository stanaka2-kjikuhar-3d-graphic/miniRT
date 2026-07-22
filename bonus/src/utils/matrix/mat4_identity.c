/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_identity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 22:20:45 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/07/22 22:37:00 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_mat4	mat4_identity(void)
{
	t_mat4	identity_mat;
	int		row;
	int		col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			if (col == row)
				identity_mat.m[row][col] = 1.0f;
			else
				identity_mat.m[row][col] = 0.0f;
			++col;
		}
		++row;
	}
	return (identity_mat);
}
