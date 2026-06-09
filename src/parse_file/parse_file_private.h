#ifndef PARSE_FILE_PRIVATE_H
# define PARSE_FILE_PRIVATE_H

#include <stdbool.h>

#include "ft_lst.h"

enum e_setting_id
{
	SETTING_AMBIENT_LIGHTING,
	SETTING_CAMERA,
	SETTING_LIGHT,
};

bool	read_file_as_line_list(int fd, t_list **line_list);
bool	read_next_line(int fd, char **next_line);
bool	validate_setting_ids(t_list *line_list);
bool	is_identifier(char const *id, char const *line);
bool	parse_settings(t_list **line_list);

#endif
