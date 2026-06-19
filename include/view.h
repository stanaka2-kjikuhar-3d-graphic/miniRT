/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 00:05:19 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/20 02:34:32 by stanaka2         ###   ########.fr       */
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
	t_ivec2		pixel_size;
	t_dvec2		pixel_half_size;
	double		aspect_ratio;
	struct s_fov
	{
		double	horizontal;
		double	vertical;
	}	fov;
	t_dvec2		world_half_size;
}	t_viewport;

t_camera const				*get_camera(void);
void						set_camera_pos(t_dvec3 pos);
void						set_camera_dir(t_dvec3 dir);
t_viewport const			*get_viewport(void);
void						set_viewport(double horizontal_fov);

#endif
