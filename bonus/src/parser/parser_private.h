/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_private.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 01:32:55 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/03 03:25:44 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_PRIVATE_H
# define PARSER_PRIVATE_H

# include <stddef.h>
# include <stdbool.h>

# include "ft_lst.h"
# include "vector.h"
# include "color.h"
# include "object.h"

# define NORMALIZED_EPSILON 0.001f // 1e-3

typedef struct s_setting_count
{
	size_t	camera;
	size_t	ambient_light;
	size_t	point_light;
}	t_setting_count;

enum e_option_id
{
	INVALID_OPTION_ID = -1,
	OPTION_TEXTURE,
	OPTION_CHECKERBOARD_COLOR1,
	OPTION_CHECKERBOARD_COLOR2,
	OPTION_CHECKERBOARD_SIZE,
	OPTION_METALNESS,
	OPTION_SHININESS
};

bool	read_file_as_line_list(int fd, t_list **line_list);
bool	read_next_line(int fd, char **next_line);
bool	validate_setting_ids(t_list *line_list);
bool	is_setting_id(char const *id, char const *line);
bool	parse_settings(t_list **line_list);
size_t	count_split(char const **split);
void	free_split(char **split);
bool	is_option_id(char const *id, char const *optional_element);
bool	parse_ambient_light_setting(char const **elements);
bool	parse_point_light_setting(char const **elements);
bool	parse_camera_setting(char const **elements);
bool	parse_spot_light_setting(char const **elements);
bool	parse_sphere_setting(char const **elements);
bool	parse_plane_setting(char const **elements);
bool	parse_cylinder_setting(char const **elements);
bool	parse_color(char const *element, t_color *color);
bool	parse_coordinate(char const *element, t_vec3 *pos);
bool	parse_brightness(char const *element, float *brightness);
bool	parse_radius(char const *element, float *radius);
bool	parse_dir(char const *element, t_vec3 *dir);
bool	parse_fov(char const *element, float *fov);
bool	parse_half_height(char const *element, float *half_height);
bool	parse_angle(char const *element, float *angle);
bool	parse_float(char const *s, float *value);
bool	parse_vec3(char const *s, t_vec3 *vector);
bool	parse_material_options(char const **optional_elements, \
			t_material *material);
bool	parse_texture(char const *element, t_image **texture);
bool	parse_size(char const *element, float *size);
bool	parse_metalness(char const *element, bool *metalness);
bool	parse_shininess(char const *element, float *shininess);

#endif
