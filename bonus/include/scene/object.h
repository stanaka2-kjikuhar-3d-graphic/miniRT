/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 00:05:37 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/17 07:11:32 by stanaka2         ###   ########.fr       */
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
# include "range.h"
# include "aabb.h"

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

typedef struct s_uv
{
	enum e_uv_type	type;
	float			pattern_size;
	t_vec2			pattern_scale;
	t_ivec2			checker_count;
	t_vec2			checker_size;
	float			u_per_v;
	t_range			u_range;
	t_range			v_range;
}	t_uv;

/*
each shape is a unit form in local space, placed by to_world.

    INFINITE_PLANE     z = 0, |x| <= half_size.x, |y| <= half_size.y
    UNIT_PLANE         z = 0, |x| <= 1, |y| <= 1
    UNIT_DISC          z = 0, x^2 + y^2 <= 1
    UNIT_SPHERE        x^2 + y^2 + z^2 = 1     z_range [-1, 1]
    UNIT_CYLINDER      x^2 + y^2       = 1     z_range [-1, 1]
    UNIT_CONE          x^2 + y^2 - z^2 = 0     z_range [ 0, 1]
    UNIT_HYPERBOLOID   x^2 + y^2 - z^2 = 1     z_range [-zc, zc]
    UNIT_PARABOLOID    x^2 + y^2 - z   = 0     z_range [ 0, 1]

  UNIT_HYPERBOLOID keeps zc per object: the unit form fixes both scales,
  so the z bound cannot be normalized to 1 as well.

  INFINITE_PLANE keeps half_size per object for the same reason: u_size
  and v_size may be given one at a time, and an infinite half cannot be
  folded into the scale. UNIT_PLANE is the case where both are finite,
  so there the bound is normalized to 1.
*/
enum e_primitive_type
{
	INFINITE_PLANE,
	UNIT_PLANE,
	UNIT_DISC,
	UNIT_SPHERE,
	UNIT_CYLINDER,
	UNIT_CONE,
	UNIT_HYPERBOLOID,
	UNIT_PARABOLOID,
};

typedef struct s_primitive
{
	enum e_primitive_type	type;
	// object_local to rebased_world
	t_mat4					to_world;
	// rebased_world to object_local
	t_mat4					to_local;
	union
	{
		t_range	z_range;
		t_vec2	half_size;
	};
}	t_primitive;

typedef struct s_object
{
	t_vec3		world_pos;
	t_vec3		world_move;
	t_material	material;
	t_uv		uv;
	t_primitive	primitive;
	t_aabb_info	aabb_info;
}	t_object;

bool			create_object(t_object const *object);
bool			get_next_object(t_object const **object);
t_object const	*get_object(size_t i);
size_t			get_object_count(void);
void			cleanup_objects(void);
float			calc_object_intersection(\
					t_object const *object, t_ray const *ray);
float			calc_aabb_intersection(t_aabb const *aabb, t_ray const *ray);
t_vec2			calc_object_uv(t_object const *object, t_vec3 point);
t_color			calc_object_color(t_object const *object, t_vec2 uv);
t_vec3			calc_object_normal(\
					t_object const *object, t_ray const *ray, t_vec3 point);
t_mat3			calc_object_tbn(\
					t_object const *object, t_vec3 point, t_vec3 normal);
t_vec3			calc_bump_mapping(\
					t_object const *object, t_vec2 uv, t_mat3 const *tbn);
t_vec3			calc_normal_mapping(\
					t_object const *object, t_vec2 uv, t_mat3 const *tbn);
bool			is_quadric_primitive(enum e_primitive_type type);

#endif
