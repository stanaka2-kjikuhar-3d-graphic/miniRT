/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 00:05:37 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/29 04:02:21 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include <stddef.h>
# include <stdbool.h>

# include "vector.h"
# include "color.h"
# include "ray.h"
# include "ft_mlx.h"

enum e_pattern_type
{
	PATTERN_SOLID,
	PATTERN_TEXTURE,
	PATTERN_CHECKERBOARD	
};

typedef struct s_checkerboard
{
	t_color	color1;
	t_color	color2;
	size_t	size;
}	t_checkerboard;

typedef struct s_material
{
	enum e_pattern_type	pattern_type;
	t_color				albedo;
	t_image				*texture;
	t_checkerboard		checkerboard;
	bool				metalness;
	double				shininess;
}	t_material;

typedef struct s_onb
{
	t_vec3	u;
	t_vec3	v;
	t_vec3	w;
}	t_onb;

enum e_object_type
{
	OBJ_SPHERE,
	OBJ_PLANE,
	OBJ_CYLINDER,
	OBJ_CIRCLE
};

typedef struct s_sphere
{
	t_material	material;
	t_vec3		center;
	float		radius;
	t_onb		onb;
}	t_sphere;

typedef struct s_plane
{
	t_material	material;
	t_vec3		center;
	t_vec3		normal;
	t_onb		onb;
}	t_plane;

typedef struct s_cylinder
{
	t_material	material;
	t_vec3		center;
	t_vec3		dir;
	float		radius;
	float		half_height;
	t_onb		onb;
}	t_cylinder;

typedef struct s_circle
{
	t_material	material;
	t_vec3		center;
	t_vec3		normal;
	float		radius;
	t_onb		onb;
}	t_circle;

typedef struct s_object
{
	union
	{
		t_sphere	sphere;
		t_plane		plane;
		t_circle	circle;
		t_cylinder	cylinder;
	};
	enum e_object_type	type;
}	t_object;

// input
typedef struct s_input_sphere
{
	t_material	material;
	t_vec3		center;
	float		radius;
}	t_input_sphere;

typedef struct s_input_plane
{
	t_material	material;
	t_vec3		center;
	t_vec3		normal;
}	t_input_plane;

typedef struct s_input_cylinder
{
	t_material	material;
	t_vec3		center;
	t_vec3		dir;
	float		radius;
	float		half_height;
}	t_input_cylinder;

typedef struct s_input_circle
{
	t_material	material;
	t_vec3		center;
	t_vec3		normal;
	float		radius;
}	t_input_circle;

bool			add_sphere(t_input_sphere const *input);
bool			add_plane(t_input_plane const *input);
bool			add_cylinder(t_input_cylinder const *input);
bool			add_circle(t_input_circle const *input);
bool			get_next_object(t_object const **object);
void			cleanup_objects(void);
float			intersect(t_object const *object, t_ray const *ray);
t_vec3			calc_normal(\
					t_object const *object, t_ray const *ray, t_vec3 point);
t_color			get_object_color(t_object const *object);

#endif
