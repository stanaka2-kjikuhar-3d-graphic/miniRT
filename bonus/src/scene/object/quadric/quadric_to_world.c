/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadric_to_world.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 17:26:39 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/08/06 22:21:12 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_mat4	quadric_to_world(\
	t_mat4 const *q_local, t_mat4 const *local_to_world)
{
	t_mat4	inv;
	t_mat4	inv_transpose;
	t_mat4	tmp;

	inv = mat4_inverse(local_to_world);
	inv_transpose = mat4_transpose(&inv);
	tmp = mat4_mul(&inv_transpose, q_local);
	return (mat4_mul(&tmp, &inv));
}
