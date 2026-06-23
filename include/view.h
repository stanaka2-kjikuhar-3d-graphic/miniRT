/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 00:05:19 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/23 13:40:09 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEW_H
# define VIEW_H

# include <stdbool.h>

# include "vector.h"

typedef struct s_camera
{
	t_vec3	pos;
	t_vec3	dir;
	t_vec3	up;
	t_vec3	right;
	float	pitch;
	float	yaw;
}	t_camera;

typedef struct s_viewport
{
	t_ivec2		pixel_size;
	t_vec2		pixel_half_size;
	float		aspect_ratio;
	float		fov;
	t_vec2		world_half_size;
}	t_viewport;

// input
typedef struct s_input_camera
{
	t_vec3	pos;
	t_vec3	dir;
}	t_input_camera;

typedef struct s_input_viewport
{
	float	fov;
}	t_input_viewport;

t_camera const				*get_camera(void);
void						set_camera(t_input_camera const *input);
void						change_camera_pos(t_vec3 pos);
void						change_camera_dir(t_vec3 dir);
void						rotate_camera_pitch(float degree);
void						rotate_camera_yaw(float degree);
t_viewport const			*get_viewport(void);
void						set_viewport(t_input_viewport const *input);
bool						change_viewport_fov(float degree);

#endif
