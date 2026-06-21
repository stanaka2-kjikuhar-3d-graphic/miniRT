/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 15:46:55 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/21 15:56:12 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "view.h"

#include "./scene_private.h"

void	rotate_camera_pitch(double degree)
{
	t_camera	*camera;

	camera = get_mutable_camera();
	camera->pitch += degree;
	if (camera->pitch <= -90.0)
		camera->pitch = -90.0;
	else if (camera->pitch >= 90.0)
		camera->pitch = 90.0;
	camera->dir = calc_camera_dir(camera->pitch, camera->yaw);
	camera->right = calc_camera_right(camera->yaw);
	camera->up = calc_camera_up(camera->right, camera->dir);
}

void	rotate_camera_yaw(double degree)
{
	t_camera	*camera;

	camera = get_mutable_camera();
	camera->yaw += degree;
	if (camera->yaw <= -180.0)
		camera->yaw += 360.0;
	else if (180.0 < camera->yaw)
		camera->yaw -= 360.0;
	camera->dir = calc_camera_dir(camera->pitch, camera->yaw);
	camera->right = calc_camera_right(camera->yaw);
	camera->up = calc_camera_up(camera->right, camera->dir);
}
