/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader_object.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 22:41:30 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/18 08:19:00 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOADER_OBJECT_H
# define LOADER_OBJECT_H

# include <stdbool.h>

# include "image.h"
# include "color.h"
# include "vector.h"
# include "object.h"
# include "id.h"

typedef struct s_material_input
{
	t_color				albedo;
	enum e_pattern_type	pattern_type;
	t_id				texture_id;
	t_checker_color		checker;
	enum e_normal_type	normal_type;
	t_id				bump_map_id;
	t_texture_id		normal_map_id;
	bool				directx_normal_map;
	float				bump_strength;
	bool				metalness;
	float				shininess;
}	t_material_input;

typedef struct s_sphere_input
{
	t_sphere			sphere;
	t_material_input	material;
	t_ivec2				checker_count;
}	t_sphere_input;

typedef struct s_plane_input
{
	t_plane				plane;
	t_material_input	material;
	float				pattern_size;
	t_ivec2				checker_count;
	t_vec2				half_size;
}	t_plane_input;

typedef struct s_cylinder_input
{
	t_cylinder			cylinder;
	t_material_input	material;
	t_ivec2				checker_count;
}	t_cylinder_input;

typedef struct s_disc_input
{
	t_disc				disc;
	t_material_input	material;
	t_uv_layout			uv_layout;
	t_ivec2				checker_count;
	float				pattern_size;
}	t_disc_input;

typedef struct s_cone_input
{
	t_cone				cone;
	t_material_input	material;
	t_ivec2				checker_count;
}	t_cone_input;

typedef struct s_hyperboloid_input
{
	t_hyperboloid		hyperboloid;
	t_material_input	material;
	t_ivec2				checker_count;
}	t_hyperboloid_input;

typedef struct s_paraboloid_input
{
	t_paraboloid		paraboloid;
	t_material_input	material;
	t_ivec2				checker_count;
}	t_paraboloid_input;

#endif
