/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 00:05:37 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/10 18:37:54 by stanaka2         ###   ########.fr       */
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
# include "matrix.h"

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
	enum e_normal_type	normal_type;
	t_image				*bump_map;
	float				bump_strength;
	t_image				*normal_map;
	bool				directx_normal_map;
	bool				metalness;
	float				shininess;
}	t_material;

enum e_uv_type
{
	UV_DEFAULT,
	UV_UPPER_CAP,
	UV_LOWER_CAP,
};

typedef struct s_range
{
	float	min;
	float	max;
}	t_range;

typedef struct s_uv
{
	enum e_uv_type	type;
	float			pattern_size;
	t_ivec2			checker_count;
	t_vec2			checker_size;
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

/*
each shape is a unit form in local space, placed by to_world.

    UNIT_SPHERE        x^2 + y^2 + z^2 = 1
    UNIT_CYLINDER      x^2 + y^2       = 1     z in [-1, 1]
    UNIT_CONE          x^2 + y^2 - z^2 = 0     z in [ 0, 1]
    UNIT_HYPERBOLOID   x^2 + y^2 - z^2 = 1     z in [-zc, zc]
    UNIT_PARABOLOID    x^2 + y^2 - z   = 0     z in [ 0, 1]
    UNIT_PLANE         z = 0
    UNIT_DISC          z = 0, x^2 + y^2 <= 1

  UNIT_HYPERBOLOID keeps zc per object: the unit form fixes both scales,
  so the z bound cannot be normalized to 1 as well.
*/
enum e_primitive_type
{
	UNIT_SPHERE,
	UNIT_CYLINDER,
	UNIT_CONE,
	UNIT_HYPERBOLOID,
	UNIT_PARABOLOID,
	UNIT_PLANE,
	UNIT_DISC
};

typedef struct s_primitive
{
	enum e_primitive_type	type;
	t_mat4					to_world;
	t_mat4					to_local;
	t_range					z_range;
}	t_primitive;

typedef struct s_aabb
{
	t_range	x;
	t_range	y;
	t_range	z;
}	t_aabb;

enum e_object_type
{
	OBJ_SPHERE,
	OBJ_PLANE,
	OBJ_CYLINDER,
	OBJ_CIRCLE,
	OBJ_CONE,
	OBJ_HYPERBOLOID,
	OBJ_PARABOLOID,
	OBJ_QUADRIC
};

typedef struct s_quadric
{
	t_mat4	q;
	t_vec3	axis;
	t_vec3	center;
	float	h_min;
	float	h_max;
	bool	finite;
}	t_quadric;

typedef struct s_sphere
{
	t_vec3	center;
	float	radius;
	t_onb	onb;
}	t_sphere;

typedef struct s_plane
{
	t_vec3	center;
	t_vec3	normal;
	t_vec2	half_size;
	t_onb	onb;
}	t_plane;

typedef struct s_cylinder
{
	t_vec3	center;
	t_vec3	dir;
	float	radius;
	float	half_height;
	t_onb	onb;
}	t_cylinder;

typedef struct s_circle
{
	t_vec3	center;
	t_vec3	normal;
	float	radius;
	t_onb	onb;
}	t_circle;

typedef struct s_cone
{
	t_vec3		center;
	t_vec3		dir;
	float		radius;
	float		height;
	float		generatrix;
	t_onb		onb;
	t_quadric	quadric;
}	t_cone;

typedef struct s_hyperboloid
{
	t_vec3		center;
	t_vec3		dir;
	float		center_radius;
	float		cap_radius;
	float		half_height;
	t_onb		onb;
	t_quadric	quadric;
}	t_hyperboloid;

typedef struct s_paraboloid
{
	t_vec3		center;
	t_vec3		dir;
	float		quadratic_coefficient;
	float		height;
	t_onb		onb;
	t_quadric	quadric;
}	t_paraboloid;

typedef struct s_object
{
	t_material			material;
	t_uv				uv;
	t_primitive			primitive;
	t_aabb				aabb;
	enum e_object_type	type;
	union
	{
		t_sphere		sphere;
		t_plane			plane;
		t_circle		circle;
		t_cylinder		cylinder;
		t_cone			cone;
		t_hyperboloid	hyperboloid;
		t_paraboloid	paraboloid;
		t_quadric		quadric;
	};
}	t_object;

typedef struct s_material_option
{
	enum e_pattern_type	pattern_type;
	t_image				*texture;
	t_color				checker_color1;
	t_color				checker_color2;
	enum e_normal_type	normal_type;
	t_image				*bump_map;
	t_image				*normal_map;
	bool				directx_normal_map;
	float				bump_strength;
	bool				metalness;
	float				shininess;
}	t_material_option;

// input
typedef struct s_input_sphere
{
	t_vec3				center;
	float				radius;
	t_color				albedo;
	struct	s_sphere_option
	{
		t_material_option	material;
		t_ivec2				checker_count;
	}					option;
}	t_input_sphere;

typedef struct s_input_plane
{
	t_vec3				center;
	t_vec3				normal;
	t_color				albedo;
	struct	s_plane_option
	{
		t_material_option	material;
		float				pattern_size;
		t_ivec2				checker_count;
		t_vec2				half_size;
	}					option;
}	t_input_plane;

typedef struct s_input_cylinder
{
	t_vec3				center;
	t_vec3				dir;
	float				radius;
	float				half_height;
	t_color				albedo;
	struct	s_cylinder_option
	{
		t_material_option	material;
		t_ivec2				checker_count;
	}					option;
}	t_input_cylinder;

typedef struct s_input_circle
{
	t_vec3				center;
	t_vec3				normal;
	float				radius;
	t_color				albedo;
	struct	s_circle_option
	{
		t_material_option	material;
		enum e_uv_type		uv_type;
		float				pattern_size;
		t_ivec2				checker_count;
		float				u_per_v;
		t_range				u_range;
		t_range				v_range;
	}					option;
}	t_input_circle;

typedef struct s_input_cone
{
	t_vec3				center;
	t_vec3				dir;
	float				radius;
	float				height;
	t_color				albedo;
	struct	s_cone_option
	{
		t_material_option	material;
		t_ivec2				checker_count;
	}					option;
}	t_input_cone;

typedef struct s_input_hyperboloid
{
	t_vec3				center;
	t_vec3				dir;
	float				center_radius;
	float				cap_radius;
	float				half_height;
	t_color				albedo;
	struct	s_hyperboloid_option
	{
		t_material_option	material;
		t_ivec2				checker_count;
	}					option;
}	t_input_hyperboloid;

typedef struct s_input_paraboloid
{
	t_vec3				center;
	t_vec3				dir;
	float				quadratic_coefficient;
	float				height;
	t_color				albedo;
	struct	s_paraboloid_option
	{
		t_material_option	material;
		t_ivec2				checker_count;
	}					option;
}	t_input_paraboloid;

bool	create_sphere(t_input_sphere const *input);
bool	create_plane(t_input_plane const *input);
bool	create_cylinder(t_input_cylinder const *input);
bool	create_circle(t_input_circle const *input);
bool	create_cone(t_input_cone const *input);
bool	create_hyperboloid(t_input_hyperboloid const *input);
bool	create_paraboloid(t_input_paraboloid const *input);
bool	get_next_object(t_object const **object);
void	cleanup_objects(void);
float	calc_object_intersection(t_object const *object, t_ray const *ray);
t_vec2	calc_object_uv(t_object const *object, t_vec3 point);
t_color	calc_object_color(t_object const *object, t_vec2 uv);
t_vec3	calc_object_normal(\
			t_object const *object, t_ray const *ray, t_vec3 point);
t_onb	calc_object_tbn(t_object const *object, t_vec3 point, t_vec3 normal);
t_vec3	calc_bump_mapping(\
			t_object const *object, t_vec2 uv, t_onb const *tbn);
t_vec3	calc_normal_mapping(\
			t_object const *object, t_vec2 uv, t_onb const *tbn);

float	quadric_eval(t_mat4 const *q, t_vec4 p);
int		solve_quadratic(float a, float b, float c, float roots[2]);
t_mat4	quadric_to_world(\
			t_mat4 const *q_local, t_mat4 const *local_to_world);
bool	quadric_in_bounds(t_quadric const *q, t_vec3 point);
float	calc_quadric_intersection(t_quadric const *q, t_ray const *ray);
t_vec3	calc_quadric_normal(\
			t_quadric const *q, t_ray const *ray, t_vec3 point);
t_vec2	calc_quadric_uv(\
			t_quadric const *q, t_onb const *onb, t_vec3 point);

#endif
