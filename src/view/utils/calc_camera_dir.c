/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_camera_dir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 12:37:30 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/20 12:41:23 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "ft_math.h"
#include "vector.h"

t_dvec3	calc_camera_dir(double pitch, double yaw)
{
	pitch *= DEG_TO_RAD;
	yaw *= DEG_TO_RAD;
	return ((t_dvec3){\
		.x = cos(pitch) * sin(yaw), \
		.y = cos(pitch) * cos(yaw), \
		.z = sin(pitch) \
	});
}
