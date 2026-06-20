/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_camera_up.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 20:21:51 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/20 12:59:34 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

// left hand coordinate system
t_dvec3	calc_camera_up(t_dvec3 right, t_dvec3 dir)
{
	return (dvec3_cross(right, dir));
}
