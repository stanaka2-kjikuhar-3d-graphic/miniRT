/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 21:55:58 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/29 22:50:34 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_lst.h"

#include "loader.h"
#include "loader_obj.h"

#include "./loader_private.h"

static const t_delete_input	g_delete_input[SCENE_INPUT_COUNT] = {\
	[CAMERA_INPUT] = {free}, \
	[AMBIENT_LIGHT_INPUT] = {free}, \
	[UNIFORM_INFINITE_LIGHT_INPUT] = {free}, \
	[POINT_LIGHT_INPUT] = {free}, \
	[SPOT_LIGHT_INPUT] = {free}, \
	[DIRECTIONAL_LIGHT_INPUT] = {free}, \
	[SPHERE_INPUT] = {free}, \
	[PLANE_INPUT] = {free}, \
	[CYLINDER_INPUT] = {free}, \
	[DISC_INPUT] = {free}, \
	[CONE_INPUT] = {free}, \
	[HYPERBOLOID_INPUT] = {free}, \
	[PARABOLOID_INPUT] = {free}, \
	[OBJ_INPUT] = {delete_obj_input} \
};

void	delete_input(void *input)
{
	if (input == NULL)
		return ;
	g_delete_input[((t_scene_input *)input)->type].delete(input);
}
