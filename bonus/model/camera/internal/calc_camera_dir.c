/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_camera_dir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 12:37:30 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/23 13:39:13 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "ft_math.h"
#include "vector.h"

t_vec3	calc_camera_dir(float pitch, float yaw)
{
	pitch *= (float)DEG_TO_RAD;
	yaw *= (float)DEG_TO_RAD;
	return ((t_vec3){\
		.x = cosf(pitch) * sinf(yaw), \
		.y = cosf(pitch) * cosf(yaw), \
		.z = sinf(pitch) \
	});
}
