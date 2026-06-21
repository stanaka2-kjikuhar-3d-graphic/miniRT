/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_private.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 22:11:33 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/21 15:48:51 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_PRIVATE_H
# define SCENE_PRIVATE_H

# include "vector.h"
# include "view.h"

t_camera	*get_mutable_camera(void);
t_dvec3		calc_camera_dir(double pitch, double yaw);
t_dvec3		calc_camera_right(double yaw);
t_dvec3		calc_camera_up(t_dvec3 right, t_dvec3 dir);

#endif
