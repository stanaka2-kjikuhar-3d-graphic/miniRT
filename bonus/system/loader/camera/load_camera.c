/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 15:32:32 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/08 23:00:53 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "camera.h"
#include "loader.h"
#include "loader_camera.h"
#include "viewport.h"

bool	load_camera(t_scene_input const *scene_input)
{
	t_camera_input const	*input;

	input = &(scene_input->camera);
	set_camera_pos(input->pos);
	set_camera_dir(input->dir);
	set_camera_fov(input->fov);
	set_viewport(input->fov);
	return (true);
}
