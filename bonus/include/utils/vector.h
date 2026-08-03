/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 16:33:20 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/01 15:42:48 by kjikuhar         ###   ########.fr       */
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

typedef struct s_vec2
{
	union
	{
		struct
		{
			float	x;
			float	y;
		};
		struct
		{
			float	u;
			float	v;
		};
		struct
		{
			float	width;
			float	height;
		};
	};
}	t_vec2;

typedef struct s_vec3
{
	float	x;
	float	y;
	float	z;
}	t_vec3;

typedef struct s_vec4
{
	float	x;
	float	y;
	float	z;
	float	w;
}	t_vec4;

t_ivec2	ivec2(int x, int y);

t_vec2	vec2(float x, float y);

t_vec3	vec3_add(t_vec3 a, t_vec3 b);
t_vec3	vec3_cross(t_vec3 a, t_vec3 b);
t_vec3	vec3_div(float t, t_vec3 v);
float	vec3_dot(t_vec3 a, t_vec3 b);
float	vec3_length(t_vec3 v);
t_vec3	vec3_normalize(t_vec3 v);
t_vec3	vec3_rotate(t_vec3 v, t_vec3 axis, float degree);
t_vec3	vec3_scale(float t, t_vec3 v);
t_vec3	vec3_sub(t_vec3 a, t_vec3 b);
t_vec3	vec3(float x, float y, float z);

float	vec4_dot(t_vec4 a, t_vec4 b);
t_vec4	vec4_from_point(t_vec3 v);
t_vec4	vec4_from_dir(t_vec3 v);
t_vec3	vec4_to_vec3(t_vec4 v);
t_vec4	vec4(float x, float y, float z, float w);

#endif
