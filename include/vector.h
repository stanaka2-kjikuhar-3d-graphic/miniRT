/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 16:33:20 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/12 01:12:00 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

enum e_axis
{
	X_AXIS,
	Y_AXIS,
	Z_AXIS,
};

typedef struct s_dvec3
{
	double	x;
	double	y;
	double	z;
}	t_dvec3;

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
