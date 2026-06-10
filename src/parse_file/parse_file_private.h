#ifndef PARSE_FILE_PRIVATE_H
# define PARSE_FILE_PRIVATE_H

#include <stdbool.h>

#include "ft_lst.h"
#include "vector.h"

enum e_setting_id
{
	SETTING_AMBIENT_LIGHTING,
	SETTING_CAMERA,
	SETTING_LIGHT,
};

enum e_color_channel
{
	RED,
	GREEN,
	BLUE
};

bool	read_file_as_line_list(int fd, t_list **line_list);
bool	read_next_line(int fd, char **next_line);
bool	validate_setting_ids(t_list *line_list);
bool	is_identifier(char const *id, char const *line);
bool	parse_settings(t_list **line_list);
void	free_splitted(char **splitted);
bool	parse_color(char const *s, int *color);
bool	parse_double(char const *s, double *value);
bool	parse_dvec3(char const *s, t_dvec3 *vector);
bool	parse_floating_point_format(const char **s);

#endif
