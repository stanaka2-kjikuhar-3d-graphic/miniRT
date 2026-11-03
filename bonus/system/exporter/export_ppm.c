/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_ppm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 23:40:00 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/11/03 23:40:00 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "config.h"
#include "logger.h"
#include "exporter.h"

#include "./exporter_private.h"

static bool	write_ppm(int fd);

bool	export_ppm(char const *scene_path)
{
	char	*path;
	int		fd;
	bool	result;

	path = calc_ppm_path(scene_path);
	if (path == NULL)
	{
		print_log_errno(LOG_ERROR);
		return (false);
	}
	fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		print_log_file(LOG_ERROR, path, ERROR_PPM_OPEN);
		free(path);
		return (false);
	}
	result = write_ppm(fd);
	if (close(fd) != 0)
		result = false;
	if (!result)
		print_log_file(LOG_ERROR, path, ERROR_PPM_WRITE);
	free(path);
	return (result);
}

static bool	write_ppm(int fd)
{
	int	y;

	if (!write_ppm_header(fd))
		return (false);
	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		if (!write_ppm_row(fd, y))
			return (false);
		++y;
	}
	return (true);
}
