/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_private.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 01:32:55 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/25 23:44:30 by stanaka2         ###   ########.fr       */
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

enum e_setting_index
{
	ID_AMBIENT_LIGHT,
	ID_CAMERA,
	ID_POINT_LIGHT,
	ID_SPHERE,
	ID_PLANE,
	ID_CYLINDER,
	ID_CONE,
	ID_HYPERBOLOID,
	ID_PARABOLOID,
	ID_SPOT_LIGHT,
	SETTING_ID_COUNT,
};

typedef struct s_setting_parser
{
	char const	*id;
	char const	*missing_err;
	char const	*dup_err;
	bool		(*parse)(char const **);
}	t_setting_parser;

typedef struct s_required_field
{
	char const	*element;
	void		*value;
	bool		(*parse)(char const *, void *);
}	t_required_field;

typedef struct s_optional_field
{
	char const	*key;
	void		*value;
	bool		(*parse)(char const *, void *);
}	t_optional_field;

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
bool				parse_spot_light(char const **elements);
bool				parse_sphere(char const **elements);
bool				parse_plane(char const **elements);
bool				parse_cylinder(char const **elements);
bool				parse_cone(char const **elements);
bool				parse_hyperboloid(char const **elements);
bool				parse_paraboloid(char const **elements);
bool				parse_required_fields(\
						t_required_field const *fields, size_t count);
bool				parse_optional_fields(char const **optional_elements, \
						t_optional_field const *fields, size_t count);
enum e_pattern_type	get_pattern_type(char const **optional_elements);
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
bool				parse_metalness(char const *element, void *value);
bool				parse_shininess(char const *element, void *value);

#endif
