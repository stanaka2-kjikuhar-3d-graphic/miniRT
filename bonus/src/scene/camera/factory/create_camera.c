/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 15:32:32 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/13 16:59:51 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "camera_factory.h"
#include "viewport.h"

void	create_camera(t_input_camera const *input)
{
	set_camera_pos(input->pos);
	set_camera_dir(input->dir);
	set_camera_fov(input->fov);
	set_viewport(input->fov);
}
