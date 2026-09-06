/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 00:05:19 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/04 21:43:16 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include <stdbool.h>

# include "vector.h"

typedef struct s_camera
{
	t_vec3	pos;
	t_vec3	dir;
	t_vec3	right;
	t_vec3	up;
	float	pitch;
	float	yaw;
	float	fov;
}	t_camera;

// input
typedef struct s_input_camera
{
	t_vec3	pos;
	t_vec3	dir;
	float	fov;
}	t_input_camera;

t_camera const	*get_camera(void);
void			set_camera(t_input_camera const *input);
void			set_camera_pos(t_vec3 pos);
void			set_camera_dir(t_vec3 dir);
bool			change_camera_fov(float degree);
void			rotate_camera_pitch(float degree);
void			rotate_camera_yaw(float degree);

#endif
