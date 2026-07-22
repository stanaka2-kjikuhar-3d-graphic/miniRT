/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 22:54:44 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/07/22 22:54:45 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

/* Columns = basis vectors rotated by Rodrigues (reuses vec3_rotate). */
t_mat4	mat4_rotate(t_vec3 axis, float degree)
{
	t_mat4	result;
	t_vec3	k;
	t_vec3	cx;
	t_vec3	cy;
	t_vec3	cz;

	k = vec3_normalize(axis);
	cx = vec3_rotate(vec3(1, 0, 0), k, degree);
	cy = vec3_rotate(vec3(0, 1, 0), k, degree);
	cz = vec3_rotate(vec3(0, 0, 1), k, degree);
	result = mat4_identity();
	result.m[0][0] = cx.x;
	result.m[1][0] = cx.y;
	result.m[2][0] = cx.z;
	result.m[0][1] = cy.x;
	result.m[1][1] = cy.y;
	result.m[2][1] = cy.z;
	result.m[0][2] = cz.x;
	result.m[1][2] = cz.y;
	result.m[2][2] = cz.z;
	return (result);
}
