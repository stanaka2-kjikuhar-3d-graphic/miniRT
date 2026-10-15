/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_private.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 22:11:33 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/24 01:18:39 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_PRIVATE_H
# define CAMERA_PRIVATE_H

# include "vector.h"
# include "camera.h"

t_camera	*get_mutable_camera(void);
t_vec3		calc_camera_dir(float pitch, float yaw);
t_vec3		calc_camera_right(float yaw);
t_vec3		calc_camera_up(t_vec3 right, t_vec3 dir);

#endif
