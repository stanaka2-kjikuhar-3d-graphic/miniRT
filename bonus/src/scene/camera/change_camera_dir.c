/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_camera_dir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 15:48:08 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/24 00:24:19 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "ft_math.h"

#include "vector.h"
#include "camera.h"

#include "./camera_private.h"

void	change_camera_dir(t_vec3 dir)
{
	t_camera	*camera;

	camera = get_mutable_camera();
	camera->dir = dir;
	camera->pitch = asinf(camera->dir.z) * (float)RAD_TO_DEG;
	camera->yaw = atan2f(camera->dir.x, camera->dir.y) * (float)RAD_TO_DEG;
	camera->right = calc_camera_right(camera->yaw);
	camera->up = calc_camera_up(camera->right, camera->dir);
}
