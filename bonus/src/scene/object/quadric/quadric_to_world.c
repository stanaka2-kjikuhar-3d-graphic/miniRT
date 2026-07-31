/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadric_to_world.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 17:26:39 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/07/31 17:27:11 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

/* Q_world = M^-T * Q_local * M^-1. See docs/quadric.md. */
t_mat4	quadric_to_world(t_mat4 q_local, t_mat4 local_to_world)
{
	t_mat4	inv;
	t_mat4	inv_transpose;

	inv = mat4_inverse(local_to_world);
	inv_transpose = mat4_transpose(inv);
	return (mat4_mul(mat4_mul(inv_transpose, q_local), inv));
}
