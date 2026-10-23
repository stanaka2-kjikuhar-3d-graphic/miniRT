/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_private.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 01:32:55 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/24 06:46:46 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_PRIVATE_H
# define PARSER_PRIVATE_H

# include <stddef.h>
# include <stdbool.h>

# include "ft_lst.h"

# include "vector.h"
# include "color.h"
# include "loader.h"
# include "texture.h"

// read_file
bool	read_file_as_line_list(int fd, t_list **line_list);
// parse_settings
bool	parse_settings(t_list **line_list, t_list **scene_input);
// parse_setting
bool	parse_ambient_light(char const **elements, t_scene_input *input);
bool	parse_point_light(char const **elements, t_scene_input *input);
bool	parse_camera(char const **elements, t_scene_input *input);
bool	parse_spot_light(char const **elements, t_scene_input *input);
bool	parse_directional_light(char const **elements, t_scene_input *input);
bool	parse_sphere(char const **elements, t_scene_input *input);
bool	parse_plane(char const **elements, t_scene_input *input);
bool	parse_cylinder(char const **elements, t_scene_input *input);
bool	parse_cone(char const **elements, t_scene_input *input);
bool	parse_hyperboloid(char const **elements, t_scene_input *input);
bool	parse_paraboloid(char const **elements, t_scene_input *input);
// parse_field
bool	parse_color(char const *element, t_color *color);
bool	parse_coordinate(char const *element, t_vec3 *coordinate);
bool	parse_brightness(char const *element, float *brightness);
bool	parse_dir(char const *element, t_vec3 *dir);
bool	parse_fov(char const *element, float *fov);
bool	parse_half_size(char const *element, float *half_size);
bool	parse_angle(char const *element, float *angle);
bool	parse_float(char const *s, float *num);
bool	parse_vec3(char const *s, t_vec3 *vector);
bool	parse_texture(char const *element, t_texture_id *id);
bool	parse_size(char const *element, float *size);
bool	parse_bool(char const *element, bool *boolean);
bool	parse_shininess(char const *element, float *shininess);
bool	parse_reflectivity(char const *element, float *reflectivity);
bool	parse_ior(char const *element, float *ior);
bool	parse_long(char const *element, long *num);
bool	parse_checker_count(char const *element, int *checker_count);
bool	parse_checker_count_even(char const *element, int *checker_count);

#endif
