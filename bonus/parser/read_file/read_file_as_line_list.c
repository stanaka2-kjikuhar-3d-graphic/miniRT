/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_as_line_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 09:26:53 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/24 06:32:02 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

#include "ft_lst.h"

#include "logger.h"

#include "./read_file_private.h"
#include "../parser_private.h"

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
		if (!ft_lst_push_back(line_list, line))
		{
			print_log_errno(LOG_ERROR);
			free(line);
			ft_lstclear(line_list, free);
			return (false);
		}
	}
}
