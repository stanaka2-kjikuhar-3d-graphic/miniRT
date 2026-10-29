/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 22:13:24 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/26 21:02:22 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
