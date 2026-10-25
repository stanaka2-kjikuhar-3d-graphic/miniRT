/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 20:45:48 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/25 22:06:05 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

# include <stdbool.h>

# include "color.h"
# include "texture.h"
# include "id.h"

typedef t_id	t_material_id;

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
	t_material_id		id;
	enum e_pattern_type	pattern_type;
	t_color				albedo;
	t_texture_id		texture_id;
	t_checker_color		checker;
	enum e_normal_type	normal_type;
	t_texture_id		bump_map_id;
	float				bump_strength;
	t_texture_id		normal_map_id;
	bool				directx_normal_map;
	bool				metalness;
	float				shininess;
	float				reflectivity;
	float				ior;
}	t_material;

t_material const	*get_material(t_material_id id);

#endif