/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 16:33:20 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/10 22:56:11 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

enum e_axis
{
	X_AXIS,
	Y_AXIS,
	Z_AXIS,
	AXIS_COUNT,
};

typedef union u_dvec3
{
	double	e[AXIS_COUNT];
	struct
	{
		double	x;
		double	y;
		double	z;
	};
}	t_dvec3;

_Static_assert(\
	offsetof(t_dvec3, x) == X_AXIS * sizeof(double), "x misaligned");
_Static_assert(\
	offsetof(t_dvec3, y) == Y_AXIS * sizeof(double), "y misaligned");
_Static_assert(offsetof(\
	t_dvec3, z) == Z_AXIS * sizeof(double), "z misaligned");

t_dvec3	dvec3_add(t_dvec3 a, t_dvec3 b);
t_dvec3	dvec3_cross(t_dvec3 a, t_dvec3 b);
double	dvec3_dot(t_dvec3 a, t_dvec3 b);
double	dvec3_length(t_dvec3 v);
t_dvec3	dvec3_normalize(t_dvec3 v);
t_dvec3	dvec3_rotate(t_dvec3 v, t_dvec3 axis, double degree);
t_dvec3	dvec3_scale(double t, t_dvec3 v);
t_dvec3	dvec3_sub(t_dvec3 a, t_dvec3 b);
t_dvec3	dvec3(double x, double y, double z);

#endif
