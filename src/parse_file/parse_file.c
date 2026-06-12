/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 21:15:21 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/12 12:22:44 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

#include "ft_lst.h"
#include "ft_error.h"
#include "./parse_file_private.h"

bool	parse_file(char const *filename)
{
	int		fd;
	t_list	*line_list;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		print_errno();
		return (false);
	}
	if (!read_file_as_line_list(fd, &line_list))
	{
		close(fd);
		return (false);
	}
	close(fd);
	if (!validate_setting_ids(line_list) \
		|| !parse_settings(&line_list))
	{
		ft_lstclear(&line_list, free);
		return (false);
	}
	return (true);
}
