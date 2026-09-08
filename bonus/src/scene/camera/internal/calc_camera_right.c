/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_camera_right.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 20:21:43 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/25 21:44:08 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "ft_math.h"
#include "vector.h"

// left hand coordinate system
t_vec3	calc_camera_right(float yaw)
{
	yaw *= (float)DEG_TO_RAD;
	return ((t_vec3){.x = cosf(yaw), .y = -sinf(yaw), .z = 0.0});
}
