/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_camera_dir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 15:48:08 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/21 15:56:04 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "ft_math.h"

#include "vector.h"
#include "view.h"

#include "./scene_private.h"

void	change_camera_dir(t_dvec3 dir)
{
	t_camera	*camera;

	camera = get_mutable_camera();
	camera->dir = dir;
	camera->pitch = asin(camera->dir.z) * RAD_TO_DEG;
	camera->yaw = atan2(camera->dir.x, camera->dir.y) * RAD_TO_DEG;
	camera->right = calc_camera_right(camera->yaw);
	camera->up = calc_camera_up(camera->right, camera->dir);
}
