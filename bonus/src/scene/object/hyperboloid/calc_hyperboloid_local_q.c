/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_hyperboloid_local_q.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 21:28:38 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/08/01 20:16:56 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_mat4	calc_hyperboloid_local_q(float a, float b, float c)
{
	t_mat4	q;

	q = mat4_identity();
	q.m[0][0] = 1.0f / (a * a);
	q.m[1][1] = 1.0f / (b * b);
	q.m[2][2] = -(1.0f / (c * c));
	q.m[3][3] = -1.0f;
	return (q);
}
