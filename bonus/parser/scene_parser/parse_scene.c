/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 21:15:21 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/30 21:57:35 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#include "ft_lst.h"

#include "logger.h"

#include "./scene_parser_private.h"
#include "../parser_private.h"

bool	parse_scene(char const *filename, t_list **input_list)
{
	int		fd;
	t_list	*line_list;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		print_log_errno(LOG_ERROR);
		return (false);
	}
	if (!read_file_as_line_list(fd, &line_list))
	{
		close(fd);
		return (false);
	}
	close(fd);
	if (!parse_settings(&line_list, input_list))
	{
		ft_lstclear(&line_list, free);
		return (false);
	}
	return (true);
}
