/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 22:13:24 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/24 01:24:06 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "ft_math.h"
#include "vector.h"
#include "camera.h"

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
	change_camera_pos(input->pos);
	change_camera_dir(input->dir);
}
