/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_cofactor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 23:11:36 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/07/22 23:11:37 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

/* Signed minor: (-1)^(row+col) * minor. */
float	mat4_cofactor(t_mat4 m, int row, int col)
{
	float	sign;

	sign = 1.0f;
	if ((row + col) % 2 == 1)
		sign = -1.0f;
	return (sign * mat4_minor(m, row, col));
}
