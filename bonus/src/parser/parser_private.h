/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_private.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 01:32:55 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/31 00:35:13 by stanaka2         ###   ########.fr       */
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
	SETTING_CONE,
	SETTING_HYPERBOLOID,
	SETTING_PARABOLOID,
	SETTING_SPOT_LIGHT,
	SETTING_ID_COUNT,
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
	REQUIRED_CENTER_DIAMETER,
	REQUIRED_CAP_DIAMETER,
	REQUIRED_HALF_HEIGHT,
	REQUIRED_HEIGHT,
	REQUIRED_COEFFICIENT,
	REQUIRED_ANGLE,
	REQUIRED_FIELD_COUNT,
};

typedef struct s_required_field
{
	void					*value;
	char const				*field;
	bool					(*parse)(char const *, void *);
}	t_required_field;

enum e_optional_field
{
	OPTIONAL_TEXTURE,
	OPTIONAL_CHECKER_COLOR1,
	OPTIONAL_CHECKER_COLOR2,
	OPTIONAL_BUMP_MAP,
	OPTIONAL_NORMAL_MAP,
	OPTIONAL_DIRECTX_NORMAL_MAP,
	OPTIONAL_BUMP_STRENGTH,
	OPTIONAL_METALNESS,
	OPTIONAL_SHININESS,
	OPTIONAL_PATTERN_SIZE,
	OPTIONAL_FIELD_COUNT,
};

enum e_field_type
{
	FIELD_IMAGE,
	FIELD_COLOR,
	FIELD_BOOL,
	FIELD_FLOAT,
};

typedef union u_field_value
{
	t_image	*image;
	t_color	color;
	bool	boolean;
	float	number;
}	t_field_value;

typedef struct s_optional_field
{
	void				*value;
	char const			*key;
	bool				(*parse)(char const *, void *);
	char const			*format_msg;
	enum e_field_type	field_type;
	t_field_value		default_value;
}	t_optional_field;

bool				read_file_as_line_list(int fd, t_list **line_list);
bool				read_next_line(int fd, char **next_line);
bool				is_blank_line(char const *line);
bool				is_comment_line(char const *line);
bool				is_setting_id(char const *id, char const *line);
bool				parse_settings(t_list **line_list);
size_t				count_split(char const **split);
void				free_split(char **split);
bool				parse_ambient_light(char const **elements);
bool				parse_point_light(char const **elements);
bool				parse_camera(char const **elements);
bool				parse_spot_light(char const **elements);
bool				parse_sphere(char const **elements);
bool				parse_plane(char const **elements);
bool				parse_cylinder(char const **elements);
bool				parse_cone(char const **elements);
bool				parse_hyperboloid(char const **elements);
bool				parse_paraboloid(char const **elements);
bool				parse_required_fields(char const **elements, \
						t_required_field const *fields, size_t count);
t_required_field	build_required_field(\
						enum e_required_field field, void *value);
void				init_optional_fields(t_optional_field *fields);
void				bind_material_option(\
					t_optional_field *fields, t_material_option *option);
void				print_unknown_option_error(t_optional_field const *fields);
bool				parse_optional_fields(char const **optional_elements, \
						t_optional_field const *fields);
enum e_pattern_type	get_pattern_type(char const **optional_elements);
enum e_normal_type	get_normal_type(char const **optional_elements);
bool				is_option_id(char const *id, char const *optional_element);
bool				parse_color(char const *element, void *value);
bool				parse_coordinate(char const *element, void *value);
bool				parse_brightness(char const *element, void *value);
bool				parse_radius(char const *element, void *value);
bool				parse_dir(char const *element, void *value);
bool				parse_fov(char const *element, void *value);
bool				parse_half_height(char const *element, void *value);
bool				parse_angle(char const *element, void *value);
bool				parse_float(char const *s, void *value);
bool				parse_vec3(char const *s, void *value);
bool				parse_texture(char const *element, void *value);
bool				parse_size(char const *element, void *value);
bool				parse_bool(char const *element, void *value);
bool				parse_shininess(char const *element, void *value);

#endif
