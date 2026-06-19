/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_camera_right.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 20:21:43 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/19 16:23:04 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "vector.h"

// left hand coordinate system
t_dvec3	calc_camera_right(t_dvec3 dir)
{
	t_dvec3	vup;

	if (fabs(dir.z) <= 1.0 - 1e-6)
		vup = (t_dvec3){0.0, 0.0, 1.0};
	else
		vup = (t_dvec3){0.0, 1.0, 0.0};
	return (dvec3_normalize(dvec3_cross(dir, vup)));
}
