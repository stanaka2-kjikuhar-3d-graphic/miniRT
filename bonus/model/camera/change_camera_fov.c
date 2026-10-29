/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_camera_fov.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 20:53:37 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/26 22:11:38 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "config.h"
#include "camera.h"
#include "viewport.h"

#include "./camera_private.h"

bool	change_camera_fov(float degree)
{
	t_camera	*camera;

	camera = get_mutable_camera();
	if (camera->fov + degree <= EPSILON \
		|| 180.0f - EPSILON <= camera->fov + degree)
	{
		return (false);
	}
	camera->fov = camera->fov + degree;
	change_viewport(camera->fov);
	return (true);
}
