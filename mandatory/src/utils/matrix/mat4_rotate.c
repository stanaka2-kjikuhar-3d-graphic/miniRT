/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 22:54:44 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/08/30 18:55:17 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

/* Columns = basis vectors rotated by Rodrigues (reuses vec3_rotate). */
t_mat4	mat4_rotate(t_vec3 axis, float degree)
{
	t_vec3	k;
	t_vec3	cx;
	t_vec3	cy;
	t_vec3	cz;

	k = vec3_normalize(axis);
	cx = vec3_rotate(vec3(1, 0, 0), k, degree);
	cy = vec3_rotate(vec3(0, 1, 0), k, degree);
	cz = vec3_rotate(vec3(0, 0, 1), k, degree);
	return ((t_mat4){.m = {\
		{cx.x, cy.x, cz.x}, \
		{cx.y, cy.y, cz.y}, \
		{cx.z, cy.z, cz.z}, \
		{0.0f, 0.0f, 0.0f, 1.0f} \
	}});
}
