/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 22:13:24 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/04 22:00:27 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "ft_math.h"
#include "vector.h"
#include "camera.h"
#include "viewport.h"

#include "./camera_private.h"

static t_camera	g_camera;

t_camera const	*get_camera(void)
{
	return (&g_camera);
}

t_camera	*get_mutable_camera(void)
{
	return (&g_camera);
}

void	set_camera(t_input_camera const *input)
{
	set_camera_pos(input->pos);
	set_camera_dir(input->dir);
	g_camera.fov = input->fov;
	set_viewport(g_camera.fov);
}
