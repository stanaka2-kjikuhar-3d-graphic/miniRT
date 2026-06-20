/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_camera_right.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 20:21:43 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/20 12:51:52 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "ft_math.h"
#include "vector.h"

// left hand coordinate system
t_dvec3	calc_camera_right(double yaw)
{
	yaw *= DEG_TO_RAD;
	return ((t_dvec3){.x = cos(yaw), .y = -sin(yaw), .z = 0.0});
}
