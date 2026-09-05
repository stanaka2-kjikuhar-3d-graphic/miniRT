/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_private.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 01:32:55 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/05 22:42:32 by stanaka2         ###   ########.fr       */
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

enum e_setting
{
	SETTING_AMBIENT_LIGHT,
	SETTING_CAMERA,
	SETTING_POINT_LIGHT,
	SETTING_SPHERE,
	SETTING_PLANE,
	SETTING_CYLINDER,
	SETTING_ID_COUNT
};

typedef struct s_setting_parser
{
	char const	*id;
	char const	*missing_err;
	char const	*dup_err;
	bool		(*parse)(char const **);
}	t_setting_parser;

enum e_required_field
{
	REQUIRED_COORDINATE,
	REQUIRED_DIR,
	REQUIRED_NORMAL,
	REQUIRED_COLOR,
	REQUIRED_BRIGHTNESS,
	REQUIRED_FOV,
	REQUIRED_DIAMETER,
	REQUIRED_HALF_HEIGHT,
	REQUIRED_FIELD_COUNT,
};

typedef struct s_required_field
{
	void					*value;
	char const				*field;
	bool					(*parse)(char const *, void *);
}	t_required_field;

bool				read_file_as_line_list(int fd, t_list **line_list);
bool				read_next_line(int fd, char **next_line);
bool				is_blank_line(char const *line);
bool				is_setting_id(char const *id, char const *line);
bool				parse_settings(t_list **line_list);
size_t				count_split(char const **split);
void				free_split(char **split);
bool				parse_ambient_light(char const **elements);
bool				parse_point_light(char const **elements);
bool				parse_camera(char const **elements);
bool				parse_sphere(char const **elements);
bool				parse_plane(char const **elements);
bool				parse_cylinder(char const **elements);
bool				parse_required_fields(char const **elements, \
						t_required_field const *fields, size_t count);
t_required_field	build_required_field(\
						enum e_required_field field, void *value);
bool				parse_color(char const *element, void *value);
bool				parse_coordinate(char const *element, void *value);
bool				parse_brightness(char const *element, void *value);
bool				parse_dir(char const *element, void *value);
bool				parse_fov(char const *element, void *value);
bool				parse_half_size(char const *element, void *value);
bool				parse_angle(char const *element, void *value);
bool				parse_float(char const *s, void *value);
bool				parse_vec3(char const *s, void *value);

#endif
