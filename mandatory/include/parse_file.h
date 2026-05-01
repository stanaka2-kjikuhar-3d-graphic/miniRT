/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 23:36:59 by stanaka2          #+#    #+#             */
/*   Updated: 2026/03/15 23:45:17 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_FILE_H
# define PARSE_FILE_H

# include "type.h"

bool	parse_file(t_cub3d *cub3d, char *filename);
char	*read_next_setting(int fd);
bool	parse_setting_line(t_setting *setting, char *line);
bool	read_map(t_map *map, int fd);
bool	parse_map_elements(t_map *map);
void	free_splitted(char **splitted);
void	replace_char(char *s, char from, char to);
bool	is_map_element(t_map *map, int x, int y);

#endif
