/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_camera_fov.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 15:34:23 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/13 17:10:23 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "camera.h"

#include "./camera_private.h"

void	set_camera_fov(float fov)
{
	get_mutable_camera()->fov = fov;
}
