/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_as_line_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 09:26:53 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/10 00:27:24 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "ft_lst.h"
#include "ft_error.h"
#include "./parse_file_private.h"

static bool	is_blank_line(const char *line);

bool	read_file_as_line_list(int fd, t_list **line_list)
{
	char	*line;

	*line_list = NULL;
	while (true)
	{
		if (!read_next_line(fd, &line))
		{
			ft_lstclear(line_list, free);
			return (false);
		}
		if (line == NULL)
			return (true);
		if (is_blank_line(line))
		{
			free(line);
			continue ;
		}
		if (!ft_lst_push_back(line_list, line))
		{
			print_error(strerror(errno));
			free(line);
			ft_lstclear(line_list, free);
			return (false);
		}
	}
}

static bool	is_blank_line(const char *line)
{
	if (!line)
		return (false);
	while (*line)
	{
		if (*line != ' ')
			return (false);
		line++;
	}
	return (true);
}
