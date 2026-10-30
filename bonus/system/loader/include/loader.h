/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 21:34:36 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/30 21:21:14 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOADER_H
# define LOADER_H

# include "ft_lst.h"

# include "loader_camera.h"
# include "loader_light.h"
# include "loader_object.h"
# include "loader_obj.h"

enum e_input
{
	// camera
	CAMERA_INPUT,
	// light
	AMBIENT_LIGHT_INPUT,
	UNIFORM_INFINITE_LIGHT_INPUT,
	POINT_LIGHT_INPUT,
	SPOT_LIGHT_INPUT,
	DIRECTIONAL_LIGHT_INPUT,
	// object
	SPHERE_INPUT,
	PLANE_INPUT,
	CYLINDER_INPUT,
	DISC_INPUT,
	CONE_INPUT,
	HYPERBOLOID_INPUT,
	PARABOLOID_INPUT,
	// obj
	OBJ_INPUT,
	// count
	INPUT_COUNT
};

typedef struct s_input
{
	enum e_input	type;
	union
	{
		// camera
		t_camera_input					camera;
		// light
		t_ambient_light_input			ambient_light;
		t_uniform_infinite_light_input	uniform_infinite_light;
		t_point_light_input				point_light;
		t_spot_light_input				spot_light;
		t_directional_light_input		directional_light;
		// object
		t_sphere_input					sphere;
		t_plane_input					plane;
		t_cylinder_input				cylinder;
		t_disc_input					disc;
		t_cone_input					cone;
		t_hyperboloid_input				hyperboloid;
		t_paraboloid_input				paraboloid;
		// obj
		t_obj_input						obj;
	};
}	t_input;

bool	load_input_list(t_list **input_list);
void	delete_input(void *input);

#endif
