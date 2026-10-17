/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 00:05:37 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/17 17:16:17 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include <stddef.h>
# include <stdbool.h>

# include "vector.h"
# include "color.h"
# include "ray.h"
# include "image.h"
# include "matrix.h"
# include "range.h"
# include "aabb.h"
# include "primitive.h"
# include "id.h"

typedef struct s_sphere
{
	t_vec3	center;
	float	radius;
}	t_sphere;

typedef struct s_plane
{
	t_vec3	center;
	t_vec3	normal;
	t_vec2	half_size;
}	t_plane;

typedef struct s_cylinder
{
	t_vec3	center;
	t_vec3	dir;
	float	radius;
	float	half_height;
}	t_cylinder;

typedef struct s_disc
{
	t_vec3	center;
	t_vec3	normal;
	float	radius;
}	t_disc;

typedef struct s_cone
{
	t_vec3	center;
	t_vec3	dir;
	float	radius;
	float	height;
}	t_cone;

typedef struct s_hyperboloid
{
	t_vec3	center;
	t_vec3	dir;
	float	center_radius;
	float	cap_radius;
	float	half_height;
}	t_hyperboloid;

typedef struct s_paraboloid
{
	t_vec3	center;
	t_vec3	dir;
	float	quadratic_coefficient;
	float	height;
}	t_paraboloid;

enum e_pattern_type
{
	PATTERN_SOLID,
	PATTERN_TEXTURE,
	PATTERN_CHECKER
};

typedef struct s_checker_color
{
	t_color	color1;
	t_color	color2;
}	t_checker_color;

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
	t_checker_color		checker;
	enum e_normal_type	normal_type;
	t_image				*bump_map;
	float				bump_strength;
	t_image				*normal_map;
	bool				directx_normal_map;
	bool				metalness;
	float				shininess;
	float				reflectivity;
	float				ior;
}	t_material;

enum e_uv_type
{
	UV_DEFAULT,
	UV_UPPER_CAP,
	UV_LOWER_CAP,
};

typedef struct s_uv_layout
{
	enum e_uv_type	type;
	float			aspect;
	t_range			u_range;
	t_range			v_range;
}	t_uv_layout;

typedef struct s_uv_checker
{
	t_ivec2	count;
	t_vec2	size;
}	t_uv_checker;

typedef struct s_uv_pattern
{
	float	size;
	t_vec2	scale;
}	t_uv_pattern;

typedef struct s_uv
{
	t_uv_layout		layout;
	t_uv_checker	checker;
	t_uv_pattern	pattern;
}	t_uv;

typedef struct s_object
{
	t_id		id;
	t_vec3		world_pos;
	t_vec3		world_move;
	t_material	material;
	t_uv		uv;
	t_primitive	primitive;
	t_aabb_info	aabb_info;
}	t_object;

void				cleanup_object(void);
bool				create_object(t_id *id);
t_object const		*get_object(t_id object_id);
t_object const		*get_object_by_index(size_t i);
size_t				get_object_count(void);
t_primitive const	*get_primitive(t_id object_id);
bool				set_cone_primitive(t_id object_id, t_cone const *cone);
bool				set_cylinder_primitive(\
						t_id object_id, t_cylinder const *cylinder);
bool				set_disc_primitive(t_id object_id, t_disc const *disc);
bool				set_hyperboloid_primitive(\
						t_id object_id, t_hyperboloid const *hyperboloid);
bool				set_paraboloid_primitive(\
						t_id object_id, t_paraboloid const *paraboloid);
bool				set_plane_primitive(t_id object_id, t_plane const *plane);
bool				set_sphere_primitive(\
						t_id object_id, t_sphere const *sphere);
t_material const	*get_material(t_id object_id);
void				set_material(t_id object_id, t_material const *material);
t_uv_layout const	*get_uv_layout(t_id object_id);
void				set_cone_uv_layout(t_id object_id, \
						enum e_uv_type type, t_cone const *cone);
void				set_cylinder_uv_layout(t_id object_id, \
						enum e_uv_type type, t_cylinder const *cylinder);
void				set_disc_uv_layout(\
						t_id object_id, t_uv_layout const *layout);
void				set_hyperboloid_uv_layout(t_id object_id, \
						enum e_uv_type type, t_hyperboloid const *hyperboloid);
void				set_paraboloid_uv_layout(t_id object_id, \
						enum e_uv_type type, t_paraboloid const *paraboloid);
void				set_plane_uv_layout(t_id object_id, enum e_uv_type type);
void				set_sphere_uv_layout(t_id object_id, enum e_uv_type type);
t_uv_checker const	*get_uv_checker(t_id object_id);
void				set_uv_checker(t_id object_id, t_ivec2 checker_count);
void				set_disc_uv_pattern(t_id object_id, float pattern_size);
void				set_plane_uv_pattern(\
						t_id object_id, float pattern_size, t_vec2 half_size);
t_aabb_info const	*get_aabb_info(t_id object_id);
void				set_cone_aabb_info(t_id object_id, t_cone const *cone);
void				set_cylinder_aabb_info(\
						t_id object_id, t_cylinder const *cylinder);
void				set_disc_aabb_info(t_id object_id, t_disc const *disc);
void				set_hyperboloid_aabb_info(\
						t_id object_id, t_hyperboloid const *hyperboloid);
void				set_paraboloid_aabb_info(\
						t_id object_id, t_primitive const *primitive);
void				set_plane_aabb_info(t_id object_id, t_plane const *plane);
void				set_sphere_aabb_info(\
						t_id object_id, t_sphere const *sphere);

#endif
