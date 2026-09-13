/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_private.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 01:32:49 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/17 07:06:21 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_PRIVATE_H
# define OBJECT_PRIVATE_H

# include "object.h"

typedef struct s_quadric_coeffs
{
	float	a;
	float	b;
	float	c;
}	t_quadric_coeffs;

typedef struct s_roots
{
	int		count;
	float	t[2];
}	t_roots;

t_mat4	unit_quadric(enum e_primitive_type type);
float	calc_primitive_intersection(\
			t_primitive const *prim, t_ray const *ray);
t_vec3	calc_primitive_normal(\
			t_primitive const *prim, t_ray const *ray, t_vec3 point);
t_vec2	calc_primitive_uv(t_primitive const *prim, t_vec3 point, \
			t_uv const *uv);
t_mat3	calc_primitive_tbn(t_primitive const *prim, t_vec3 point, \
			t_vec3 normal, enum e_uv_type uv_type);
bool	is_planar_primitive(enum e_primitive_type type);
bool	is_quadric_primitive(enum e_primitive_type type);
float	calc_planar_intersection(\
			t_primitive const *prim, t_ray const *local);
float	calc_quadric_intersection(\
			t_primitive const *prim, t_ray const *local);
t_vec2	adjust_uv_range(t_vec2 uv, t_range u_range, t_range v_range);

#endif
