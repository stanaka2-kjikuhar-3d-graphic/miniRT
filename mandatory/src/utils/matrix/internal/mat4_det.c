/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_det.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 23:11:51 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/08/06 22:20:13 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

/* Laplace expansion along the first row. */
float	mat4_det(t_mat4 const *m)
{
	float	det;
	int		col;

	det = 0.0f;
	col = 0;
	while (col < 4)
	{
		det += m->m[0][col] * mat4_cofactor(m, 0, col);
		++col;
	}
	return (det);
}
