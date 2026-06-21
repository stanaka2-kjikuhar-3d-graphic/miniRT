/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file_private.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 01:32:55 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/21 14:39:32 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_FILE_PRIVATE_H
# define PARSE_FILE_PRIVATE_H

# include <stddef.h>
# include <stdbool.h>

# include "ft_lst.h"
# include "vector.h"
# include "color.h"

enum e_setting_id
{
	SETTING_ambient_light,
	SETTING_LIGHT,
	SETTING_CAMERA,
};

bool	read_file_as_line_list(int fd, t_list **line_list);
bool	read_next_line(int fd, char **next_line);
bool	validate_setting_ids(t_list *line_list);
bool	is_identifier(char const *id, char const *line);
bool	parse_settings(t_list **line_list);
size_t	count_split(char const **split);
void	free_split(char **split);
bool	parse_ambient_light_setting(char const **elements);
bool	parse_light_setting(char const **elements);
bool	parse_camera_setting(char const **elements);
bool	parse_sphere_setting(char const **elements);
bool	parse_plane_setting(char const **elements);
bool	parse_cylinder_setting(char const **elements);
bool	parse_color(char const *element, t_color *color);
bool	parse_pos(char const *element, t_dvec3 *pos);
bool	parse_brightness(char const *element, double *brightness);
bool	parse_radius(char const *element, double *radius);
bool	parse_dir(char const *element, t_dvec3 *dir);
bool	parse_fov(char const *element, double *fov);
bool	parse_half_height(char const *element, double *half_height);
bool	parse_angle(char const *element, double *angle);
bool	parse_double(char const *s, double *value);
bool	parse_dvec3(char const *s, t_dvec3 *vector);

#endif
