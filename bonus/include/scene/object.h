/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 00:05:37 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/19 17:34:57 by stanaka2         ###   ########.fr       */
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
	PATTERN_CHECKER
};

typedef struct s_checker
{
	t_color	color1;
	t_color	color2;
	t_vec2	size;
}	t_checker;

enum e_normal_type
{
	NORMAL_OBJECT,
	BUMP_MAP,
	NORMAL_MAP
};

typedef struct s_material
{
	enum e_pattern_type	pattern_type;
	t_color				albedo;
	t_image				*texture;
	t_checker			checker;
	
	t_image				*bump_map;
	t_image				*normal_map;
	bool				metalness;
	float				shininess;
}	t_material;

enum e_uv_type
{
	UV_PLANE,
	UV_UPPER_CAP,
	UV_LOWER_CAP,
	UV_CYLINDER,
	UV_SPHERE,
};

typedef struct s_range
{
	float	max;
	float	min;
}	t_range;

typedef struct s_uv
{
	enum e_uv_type	type;
	float			pattern_size;
	float			u_per_v;
	t_range			u_range;
	t_range			v_range;
}	t_uv;

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
	t_vec3		center;
	float		radius;
	t_onb		onb;
}	t_sphere;

typedef struct s_plane
{
	t_vec3		center;
	t_vec3		normal;
	t_onb		onb;
}	t_plane;

typedef struct s_cylinder
{
	t_vec3		center;
	t_vec3		dir;
	float		radius;
	float		half_height;
	t_onb		onb;
}	t_cylinder;

typedef struct s_circle
{
	t_vec3		center;
	t_vec3		normal;
	float		radius;
	t_onb		onb;
}	t_circle;

typedef struct s_object
{
	t_material			material;
	t_uv				uv;
	enum e_object_type	type;
	union
	{
		t_sphere	sphere;
		t_plane		plane;
		t_circle	circle;
		t_cylinder	cylinder;
	};
}	t_object;

// input
typedef struct s_input_sphere
{
	t_vec3	center;
	float	radius;
	t_color	albedo;
	struct	s_sphere_option
	{
		enum e_pattern_type	pattern_type;
		t_image				*texture;
		t_color				checker_color1;
		t_color				checker_color2;
		t_image				*bump_map;
		t_image				*normal_map;
		bool				metalness;
		float				shininess;
	}	option;
}	t_input_sphere;

typedef struct s_input_plane
{
	t_vec3	center;
	t_vec3	normal;
	t_color	albedo;
	struct	s_plane_option
	{
		enum e_pattern_type	pattern_type;
		t_image				*texture;
		t_color				checker_color1;
		t_color				checker_color2;
		t_image				*bump_map;
		t_image				*normal_map;
		bool				metalness;
		float				shininess;
		float				pattern_size;
	}	option;
}	t_input_plane;

typedef struct s_input_cylinder
{
	t_vec3	center;
	t_vec3	dir;
	float	radius;
	float	half_height;
	t_color	albedo;
	struct	s_cylinder_option
	{
		enum e_pattern_type	pattern_type;
		t_image				*texture;
		t_color				checker_color1;
		t_color				checker_color2;
		t_image				*bump_map;
		t_image				*normal_map;
		bool				metalness;
		float				shininess;
	}	option;
}	t_input_cylinder;

typedef struct s_input_circle
{
	t_vec3	center;
	t_vec3	normal;
	float	radius;
	t_color	albedo;
	struct	s_circle_option
	{
		enum e_pattern_type	pattern_type;
		t_image				*texture;
		t_color				checker_color1;
		t_color				checker_color2;
		t_image				*bump_map;
		t_image				*normal_map;
		bool				metalness;
		float				shininess;
		enum e_uv_type		uv_type;
		float				pattern_size;
		float				u_per_v;
		t_range				u_range;
		t_range				v_range;
	}	option;
}	t_input_circle;

void	init_material(t_material *material);
bool	create_sphere(t_input_sphere const *input);
bool	create_plane(t_input_plane const *input);
bool	create_cylinder(t_input_cylinder const *input);
bool	create_circle(t_input_circle const *input);
bool	get_next_object(t_object const **object);
void	cleanup_objects(void);
float	calc_object_intersection(t_object const *object, t_ray const *ray);
t_vec2	calc_object_uv(t_object const *object, t_vec3 point);
t_color	calc_object_color(t_object const *object, t_vec2 uv);
t_vec3	calc_object_normal(\
			t_object const *object, t_ray const *ray, t_vec3 point);

#endif
