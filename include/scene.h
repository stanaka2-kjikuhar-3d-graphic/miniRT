#ifndef SCENE_H
# define SCENE_H

#include <stdint.h>

#include "vector.h"

# define VIEWPORT_WIDTH 1920
# define VIEWPORT_HEIGHT 1080

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
		uint32_t	width;
		uint32_t	height;
	}	pixel;
	double		aspect_ratio;
	double		horizontal_fov;
	double		vertical_fov;
	double		half_width;
	double		half_height;
}	t_viewport;

typedef struct s_ambient_lighting
{
	double	brightness;
	int		color;
}	t_ambient_lighting;

typedef struct s_light
{
	t_dvec3	pos;
	double	brightness;
	int		color;
}	t_light;


t_camera const				*get_camera(void);
void						set_camera_pos(t_dvec3 pos);
void						set_camera_dir(t_dvec3 dir);
t_ambient_lighting const	*get_ambient_lighting(void);
void						set_ambient_lighting_brightness(double brightness);
void						set_ambient_lighting_color(double color);
t_light const				*get_light(void);
void						set_light_pos(t_dvec3 pos);
void						set_light_brightness(double brightness);
void						set_light_color(double color);

#endif
