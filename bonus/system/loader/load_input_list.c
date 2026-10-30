/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_input_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 21:22:09 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/30 21:22:14 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

#include "ft_lst.h"

#include "loader.h"

#include "./loader_private.h"

static const t_load_input	g_load_input[INPUT_COUNT] = {\
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

bool	load_input_list(t_list **input_list)
{
	t_input	*input;

	while (*input_list != NULL)
	{
		input = ft_lst_pop_front(input_list);
		if (!g_load_input[input->type].load(input))
		{
			delete_input(input);
			return (false);
		}
		delete_input(input);
	}
	return (true);
}
