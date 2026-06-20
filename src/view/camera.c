/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 22:13:24 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/20 13:28:48 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "config.h"
#include "ft_math.h"
#include "vector.h"
#include "view.h"

#include "./scene_private.h"

static t_camera	g_camera;

t_camera const	*get_camera(void)
{
	return (&g_camera);
}

void	set_camera_pos(t_dvec3 pos)
{
	g_camera.pos = pos;
}

void	set_camera_dir(t_dvec3 dir)
{
	g_camera.dir = dir;
	g_camera.pitch = asin(g_camera.dir.z) * RAD_TO_DEG;
	g_camera.yaw = atan2(g_camera.dir.x, g_camera.dir.y) * RAD_TO_DEG;
	g_camera.right = calc_camera_right(g_camera.yaw);
	g_camera.up = calc_camera_up(g_camera.right, g_camera.dir);
}

void	rotate_camera_pitch(double degree)
{
	g_camera.pitch += degree;
	if (g_camera.pitch <= -90.0)
		g_camera.pitch = -90.0;
	else if (g_camera.pitch >= 90.0)
		g_camera.pitch = 90.0;
	g_camera.dir = calc_camera_dir(g_camera.pitch, g_camera.yaw);
	g_camera.right = calc_camera_right(g_camera.yaw);
	g_camera.up = calc_camera_up(g_camera.right, g_camera.dir);
}

void	rotate_camera_yaw(double degree)
{
	g_camera.yaw += degree;
	if (g_camera.yaw <= -180.0)
		g_camera.yaw += 360.0;
	else if (180.0 < g_camera.yaw)
		g_camera.yaw -= 360.0;
	g_camera.dir = calc_camera_dir(g_camera.pitch, g_camera.yaw);
	g_camera.right = calc_camera_right(g_camera.yaw);
	g_camera.up = calc_camera_up(g_camera.right, g_camera.dir);
}
