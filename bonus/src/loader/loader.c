/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 21:59:09 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/17 07:51:58 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

#include "ft_lst.h"

#include "loader.h"

#include "./loader_private.h"

static const t_loader	g_loader[SCENE_INPUT_COUNT] = {\
	[CAMERA_INPUT] = {create_camera}, \
	[AMBIENT_LIGHT_INPUT] = {create_ambient_light}, \
	[UNIFORM_INFINITE_LIGHT_INPUT] = {create_uniform_infinite_light}, \
	[POINT_LIGHT_INPUT] = {create_point_light}, \
	[SPOT_LIGHT_INPUT] = {create_spot_light}, \
	[DIRECTIONAL_LIGHT_INPUT] = {create_directional_light}, \
	[SPHERE_INPUT] = {create_sphere}, \
	[PLANE_INPUT] = {create_plane}, \
	[CYLINDER_INPUT] = {create_cylinder}, \
	[DISC_INPUT] = {create_disc}, \
	[CONE_INPUT] = {create_cone}, \
	[HYPERBOLOID_INPUT] = {create_hyperboloid}, \
	[PARABOLOID_INPUT] = {create_paraboloid},
};

bool	loader(t_list **scene_input)
{
	t_scene_input	*input;

	while (*scene_input != NULL)
	{
		input = ft_lst_pop_front(scene_input);
		if (!g_loader[input->type].load(input))
		{
			free(input);
			return (false);
		}
		free(input);
	}
	return (true);
}
