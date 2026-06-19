/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 00:05:19 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/19 18:59:03 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>

# include "vector.h"
# include "color.h"

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

typedef struct s_ambient_lighting
{
	t_color	radiance;
	t_color	color;
	double	brightness;
}	t_ambient_lighting;

typedef struct s_light
{
	t_dvec3	pos;
	t_color	radiance;
	t_color	color;
	double	brightness;
}	t_light;

t_camera const				*get_camera(void);
void						set_camera_pos(t_dvec3 pos);
void						set_camera_dir(t_dvec3 dir);
t_ambient_lighting const	*get_ambient_lighting(void);
void						set_ambient_lighting(\
								t_color color, double brightness);
bool						get_next_light(t_light const	**light);
bool						add_light(\
								t_dvec3 pos, t_color color, double brightness);
bool						allocate_lights(size_t add_count);
void						cleanup_lights(void);
t_viewport const			*get_viewport(void);
void						set_viewport(double horizontal_fov);

#endif
