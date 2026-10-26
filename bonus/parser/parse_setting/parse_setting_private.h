/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_setting_private.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 06:27:29 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/26 21:42:23 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_SETTING_PRIVATE_H
# define PARSE_SETTING_PRIVATE_H

# include <stddef.h>
# include <stdbool.h>

# include "vector.h"
# include "material.h"
# include "color.h"
# include "texture.h"
# include "loader_object.h"

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
	OPTIONAL_REFLECTIVITY,
	OPTIONAL_IOR,
	OPTIONAL_PATTERN_SIZE,
	OPTIONAL_U_SIZE,
	OPTIONAL_V_SIZE,
	OPTIONAL_CHECKER_COUNT_U,
	OPTIONAL_CHECKER_COUNT_V,
	OPTIONAL_CHECKER_COUNT_U_EVEN,
	OPTIONAL_CHECKER_COUNT_V_EVEN,
	OPTIONAL_FIELD_COUNT,
};

enum e_field_type
{
	FIELD_VEC3,
	FIELD_COLOR,
	FIELD_FLOAT,
	FIELD_INT,
	FIELD_LONG,
	FIELD_BOOL,
	FIELD_TEXTURE_ID
};

typedef union u_field_parser
{
	bool	(*vector)(char const *, t_vec3 *);
	bool	(*color)(char const *, t_color *);
	bool	(*floating_point)(char const *, float *);
	bool	(*integer)(char const *, int *);
	bool	(*long_integer)(char const *, long *);
	bool	(*boolean)(char const *, bool *);
	bool	(*texture_id)(char const *, t_texture_id *);
}	t_field_parser;

union u_field_value
{
	t_vec3			*vector;
	t_color			*color;
	float			*floating_point;
	int				*integer;
	long			*long_integer;
	bool			*boolean;
	t_texture_id	*texture_id;
};

union u_default_field_value
{
	t_vec3			vector;
	t_color			color;
	float			floating_point;
	int				integer;
	long			long_integer;
	bool			boolean;
	t_texture_id	texture_id;
};

typedef struct s_required_field
{
	char const				*field;
	enum e_field_type		field_type;
	union u_field_parser	parser;
	union u_field_value		value;
	bool					is_set;
}	t_required_field;

typedef struct s_optional_field
{
	char const					*key;
	char const					*format_msg;
	enum e_field_type			field_type;
	union u_field_parser		parser;
	union u_field_value			value;
	union u_default_field_value	default_value;
	bool						is_set;
}	t_optional_field;

size_t				count_split(char const **split);
t_required_field	bind_required_field(\
						enum e_required_field field, void *value);
void				init_optional_fields(t_optional_field *fields);
void				bind_optional_field(t_optional_field *fields, \
						enum e_optional_field optional_type, void *value);
void				bind_material_fields(t_optional_field *fields, \
						t_material_input *material);
void				bind_field_value(enum e_field_type type, bool *is_set, \
						union u_field_value *value, void *ptr);
bool				is_option_id(char const *id, char const *optional_element);
void				set_default_values(t_optional_field *fields);
void				set_default_field_value(enum e_field_type type, \
						union u_field_value *value, \
						union u_default_field_value default_value);
bool				parse_required_fields(char const **elements, \
						t_required_field const *fields, size_t count);
bool				parse_optional_fields(char const **optional_elements, \
						t_optional_field *fields);
bool				parse_field(enum e_field_type type, \
						union u_field_parser parser, char const *element, \
						union u_field_value value);
enum e_pattern_type	get_pattern_type(char const **optional_elements);
enum e_normal_type	get_normal_type(char const **optional_elements);

#endif
