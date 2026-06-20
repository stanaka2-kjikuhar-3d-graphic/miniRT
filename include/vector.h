/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 16:33:20 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/20 02:06:37 by stanaka2         ###   ########.fr       */
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
	union
	{
		struct
		{
			double	x;
			double	y;
			double	z;
		};
		struct
		{
			double	u;
			double	v;
			double	w;
		};
	};
}	t_dvec3;

typedef struct s_dvec2
{
	union
	{
		struct
		{
			double	x;
			double	y;
		};
		struct
		{
			double	u;
			double	v;
		};
		struct
		{
			double	width;
			double	height;
		};
	};
}	t_dvec2;

typedef struct s_ivec2
{
	union
	{
		struct
		{
			int	x;
			int	y;
		};
		struct
		{
			int	u;
			int	v;
		};
		struct
		{
			int	width;
			int	height;
		};
	};
}	t_ivec2;

t_dvec3	dvec3_add(t_dvec3 a, t_dvec3 b);
t_dvec3	dvec3_cross(t_dvec3 a, t_dvec3 b);
double	dvec3_dot(t_dvec3 a, t_dvec3 b);
double	dvec3_length(t_dvec3 v);
t_dvec3	dvec3_normalize(t_dvec3 v);
t_dvec3	dvec3_rotate(t_dvec3 v, t_dvec3 axis, double degree);
t_dvec3	dvec3_scale(double t, t_dvec3 v);
t_dvec3	dvec3_sub(t_dvec3 a, t_dvec3 b);
t_dvec3	dvec3(double x, double y, double z);

t_dvec2	dvec2(double x, double y);

t_ivec2	ivec2(int x, int y);

#endif
