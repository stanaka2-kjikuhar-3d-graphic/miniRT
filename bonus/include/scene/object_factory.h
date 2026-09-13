/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_factory.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 16:01:19 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/13 16:40:58 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_FACTORY_H
# define OBJECT_FACTORY_H

# include <stdbool.h>

# include "ft_mlx.h"
# include "color.h"
# include "vector.h"
# include "object.h"

typedef struct s_input_material_option
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
}	t_input_material_option;

typedef struct s_input_sphere
{
	t_vec3	center;
	float	radius;
	t_color	albedo;
	struct	s_sphere_option
	{
		t_input_material_option	material;
		t_ivec2					checker_count;
	}	option;
}	t_input_sphere;

typedef struct s_input_plane
{
	t_vec3	center;
	t_vec3	normal;
	t_color	albedo;
	struct	s_plane_option
	{
		t_input_material_option	material;
		float					pattern_size;
		t_ivec2					checker_count;
		t_vec2					half_size;
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
		t_input_material_option	material;
		t_ivec2					checker_count;
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
		t_input_material_option	material;
		enum e_uv_type			uv_type;
		float					pattern_size;
		t_ivec2					checker_count;
		float					u_per_v;
		t_range					u_range;
		t_range					v_range;
	}	option;
}	t_input_circle;

typedef struct s_input_cone
{
	t_vec3	center;
	t_vec3	dir;
	float	radius;
	float	height;
	t_color	albedo;
	struct	s_cone_option
	{
		t_input_material_option	material;
		t_ivec2					checker_count;
	}	option;
}	t_input_cone;

typedef struct s_input_hyperboloid
{
	t_vec3	center;
	t_vec3	dir;
	float	center_radius;
	float	cap_radius;
	float	half_height;
	t_color	albedo;
	struct	s_hyperboloid_option
	{
		t_input_material_option	material;
		t_ivec2					checker_count;
	}	option;
}	t_input_hyperboloid;

typedef struct s_input_paraboloid
{
	t_vec3	center;
	t_vec3	dir;
	float	quadratic_coefficient;
	float	height;
	t_color	albedo;
	struct	s_paraboloid_option
	{
		t_input_material_option	material;
		t_ivec2					checker_count;
	}	option;
}	t_input_paraboloid;

bool	create_sphere(t_input_sphere const *input);
bool	create_plane(t_input_plane const *input);
bool	create_cylinder(t_input_cylinder const *input);
bool	create_circle(t_input_circle const *input);
bool	create_cone(t_input_cone const *input);
bool	create_hyperboloid(t_input_hyperboloid const *input);
bool	create_paraboloid(t_input_paraboloid const *input);

#endif
