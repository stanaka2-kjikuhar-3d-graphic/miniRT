/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_private.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 21:34:37 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/30 21:44:24 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_PRIVATE_H
# define PARSER_PRIVATE_H

# include <stdbool.h>

# include "ft_lst.h"

bool	read_file_as_line_list(int fd, t_list **line_list);
bool	is_blank_line(char const *line);
bool	is_comment_line(char const *line);
void	free_split(char **split);

#endif
