/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 16:33:20 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/30 16:19:08 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <assert.h>
# include <stddef.h>

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
	union
	{
		float	e[3];
		struct
		{
			float	x;
			float	y;
			float	z;
		};
		struct
		{
			float	u;
			float	v;
			float	w;
		};
	};
}	t_vec3;

# define VEC3_ASSERTION "Error\nmemory alignment of t_vec3."

static_assert(offsetof(t_vec3, x) == 0, VEC3_ASSERTION " x != e[0]");
static_assert(offsetof(t_vec3, y) == sizeof(float), \
				VEC3_ASSERTION " y != e[1]");
static_assert(offsetof(t_vec3, z) == 2 * sizeof(float), \
				VEC3_ASSERTION " z != e[2]");

typedef struct s_vec4
{
	union
	{
		float	e[4];
		struct
		{
			float	x;
			float	y;
			float	z;
			float	w;
		};
	};
}	t_vec4;

# define VEC4_ASSERTION "Error\nmemory alignment of t_vec4."

static_assert(offsetof(t_vec4, x) == 0, VEC4_ASSERTION " x != e[0]");
static_assert(offsetof(t_vec4, y) == sizeof(float), \
				VEC4_ASSERTION " y != e[1]");
static_assert(offsetof(t_vec4, z) == 2 * sizeof(float), \
				VEC4_ASSERTION " z != e[2]");
static_assert(offsetof(t_vec4, w) == 3 * sizeof(float), \
				VEC4_ASSERTION " w != e[3]");

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
