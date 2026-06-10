/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 22:13:24 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/10 23:13:57 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "scene.h"
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
	g_camera.right = calc_camera_right(g_camera.dir);
	g_camera.up = calc_camera_up(g_camera.right, g_camera.dir);
}
