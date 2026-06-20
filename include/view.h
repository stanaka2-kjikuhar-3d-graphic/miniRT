/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 00:05:19 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/20 13:14:35 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEW_H
# define VIEW_H

# include <stdbool.h>

# include "vector.h"

typedef struct s_camera
{
	t_dvec3	pos;
	t_dvec3	dir;
	t_dvec3	up;
	t_dvec3	right;
	double	pitch;
	double	yaw;
}	t_camera;

typedef struct s_viewport
{
	t_ivec2		pixel_size;
	t_dvec2		pixel_half_size;
	double		aspect_ratio;
	double		fov;
	t_dvec2		world_half_size;
}	t_viewport;

t_camera const				*get_camera(void);
void						set_camera_pos(t_dvec3 pos);
void						set_camera_dir(t_dvec3 dir);
void						rotate_camera_pitch(double degree);
void						rotate_camera_yaw(double degree);
t_viewport const			*get_viewport(void);
void						set_viewport(double fov);
bool						change_fov(double degree);

#endif
