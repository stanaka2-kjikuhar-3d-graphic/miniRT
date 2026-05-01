/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_next_setting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 22:44:28 by stanaka2          #+#    #+#             */
/*   Updated: 2026/03/11 16:02:43 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*read_next_setting(int fd)
{
	char	*line;

	while (true)
	{
		line = get_next_line(fd);
		if (errno)
		{
			print_error(strerror(errno));
			return (NULL);
		}
		if (line == NULL)
		{
			print_error(ERROR_SETTING_INCOMPLETE);
			return (NULL);
		}
		replace_char(line, '\n', '\0');
		if (line[0] == '\0')
		{
			free(line);
			continue ;
		}
		return (line);
	}
}
