/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_private.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 01:32:49 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/05 22:08:18 by stanaka2         ###   ########.fr       */
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

typedef struct s_primitive_frame
{
	enum e_primitive_type	type;
	t_mat3					basis;
	t_vec3					origin;
	t_vec3					scale;
	t_range					z_range;
}	t_primitive_frame;

bool	create_object(t_object const *object);
t_mat3	calc_onb(t_vec3 n);
bool	build_primitive(t_primitive_frame const *frame, t_primitive *out);
t_mat4	unit_quadric(enum e_primitive_type type);
float	calc_primitive_intersection(\
			t_primitive const *prim, t_ray const *ray);
t_vec3	calc_primitive_normal(\
			t_primitive const *prim, t_ray const *ray, t_vec3 point);
bool	is_planar_primitive(enum e_primitive_type type);
bool	is_quadric_primitive(enum e_primitive_type type);
float	calc_planar_intersection(\
			t_primitive const *prim, t_ray const *local);
float	calc_quadric_intersection(\
			t_primitive const *prim, t_ray const *local);

#endif
