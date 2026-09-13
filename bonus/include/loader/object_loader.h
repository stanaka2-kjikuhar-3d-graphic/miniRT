/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_loader.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 22:41:30 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/15 21:35:31 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_LOADER_H
# define OBJECT_LOADER_H

# include <stdbool.h>

# include "ft_mlx.h"
# include "color.h"
# include "vector.h"
# include "object.h"

typedef struct s_material_option_input
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
}	t_material_option_input;

typedef struct s_sphere_input
{
	t_vec3	center;
	float	radius;
	t_color	albedo;
	struct	s_sphere_option
	{
		t_material_option_input	material;
		t_ivec2					checker_count;
	}	option;
}	t_sphere_input;

typedef struct s_plane_input
{
	t_vec3	center;
	t_vec3	normal;
	t_color	albedo;
	struct	s_plane_option
	{
		t_material_option_input	material;
		float					pattern_size;
		t_ivec2					checker_count;
		t_vec2					half_size;
	}	option;
}	t_plane_input;

typedef struct s_cylinder_input
{
	t_vec3	center;
	t_vec3	dir;
	float	radius;
	float	half_height;
	t_color	albedo;
	struct	s_cylinder_option
	{
		t_material_option_input	material;
		t_ivec2					checker_count;
	}	option;
}	t_cylinder_input;

typedef struct s_disc_input
{
	t_vec3	center;
	t_vec3	normal;
	float	radius;
	t_color	albedo;
	struct	s_disc_option
	{
		t_material_option_input	material;
		enum e_uv_type			uv_type;
		float					pattern_size;
		t_ivec2					checker_count;
		float					u_per_v;
		t_range					u_range;
		t_range					v_range;
	}	option;
}	t_disc_input;

typedef struct s_cone_input
{
	t_vec3	center;
	t_vec3	dir;
	float	radius;
	float	height;
	t_color	albedo;
	struct	s_cone_option
	{
		t_material_option_input	material;
		t_ivec2					checker_count;
	}	option;
}	t_cone_input;

typedef struct s_hyperboloid_input
{
	t_vec3	center;
	t_vec3	dir;
	float	center_radius;
	float	cap_radius;
	float	half_height;
	t_color	albedo;
	struct	s_hyperboloid_option
	{
		t_material_option_input	material;
		t_ivec2					checker_count;
	}	option;
}	t_hyperboloid_input;

typedef struct s_paraboloid_input
{
	t_vec3	center;
	t_vec3	dir;
	float	quadratic_coefficient;
	float	height;
	t_color	albedo;
	struct	s_paraboloid_option
	{
		t_material_option_input	material;
		t_ivec2					checker_count;
	}	option;
}	t_paraboloid_input;

#endif
