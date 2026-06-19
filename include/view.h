/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 00:05:19 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/19 21:00:00 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEW_H
# define VIEW_H

# include "vector.h"

typedef struct s_camera
{
	t_dvec3	pos;
	t_dvec3	dir;
	t_dvec3	up;
	t_dvec3	right;
}	t_camera;

typedef struct s_viewport
{
	struct s_viewport_pixel
	{
		int	width;
		int	height;
	}	pixel;
	double		aspect_ratio;
	double		horizontal_fov;
	double		vertical_fov;
	double		half_width;
	double		half_height;
}	t_viewport;



t_camera const				*get_camera(void);
void						set_camera_pos(t_dvec3 pos);
void						set_camera_dir(t_dvec3 dir);
t_viewport const			*get_viewport(void);
void						set_viewport(double horizontal_fov);

#endif
