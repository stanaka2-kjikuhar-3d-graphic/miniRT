/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 21:59:09 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/29 22:56:27 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

#include "ft_lst.h"

#include "loader.h"

#include "./loader_private.h"

static const t_load_input	g_load_input[SCENE_INPUT_COUNT] = {\
	[CAMERA_INPUT] = {load_camera}, \
	[AMBIENT_LIGHT_INPUT] = {load_ambient_light}, \
	[UNIFORM_INFINITE_LIGHT_INPUT] = {load_uniform_infinite_light}, \
	[POINT_LIGHT_INPUT] = {load_point_light}, \
	[SPOT_LIGHT_INPUT] = {load_spot_light}, \
	[DIRECTIONAL_LIGHT_INPUT] = {load_directional_light}, \
	[SPHERE_INPUT] = {load_sphere}, \
	[PLANE_INPUT] = {load_plane}, \
	[CYLINDER_INPUT] = {load_cylinder}, \
	[DISC_INPUT] = {load_disc}, \
	[CONE_INPUT] = {load_cone}, \
	[HYPERBOLOID_INPUT] = {load_hyperboloid}, \
	[PARABOLOID_INPUT] = {load_paraboloid}, \
	[OBJ_INPUT] = {load_obj} \
};

bool	load_input(t_list **scene_input)
{
	t_scene_input	*input;

	while (*scene_input != NULL)
	{
		input = ft_lst_pop_front(scene_input);
		if (!g_load_input[input->type].load(input))
		{
			free(input);
			return (false);
		}
		free(input);
	}
	return (true);
}
