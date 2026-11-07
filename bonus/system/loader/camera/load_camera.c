/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 15:32:32 by stanaka2          #+#    #+#             */
/*   Updated: 2026/11/07 18:35:52 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "camera.h"
#include "loader.h"
#include "loader_camera.h"

bool	load_camera(t_input const *input)
{
	t_camera_input const	*camera;

	camera = &(input->camera);
	set_camera_pos(camera->pos);
	set_camera_dir(camera->dir);
	set_camera_fov(camera->fov);
	set_viewport(camera->fov);
	return (true);
}
