/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_private.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 22:11:33 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/23 13:39:13 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_PRIVATE_H
# define SCENE_PRIVATE_H

# include "vector.h"
# include "view.h"

t_camera	*get_mutable_camera(void);
t_vec3		calc_camera_dir(float pitch, float yaw);
t_vec3		calc_camera_right(float yaw);
t_vec3		calc_camera_up(t_vec3 right, t_vec3 dir);

#endif
