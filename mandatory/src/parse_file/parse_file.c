/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 18:25:07 by stanaka2          #+#    #+#             */
/*   Updated: 2026/03/16 20:02:00 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	validate_filename(char *filepath);
static bool	parse_settings(t_setting *setting, int fd);
static bool	parse_map(t_map *map, int fd);

bool	parse_file(t_cub3d *cub3d, char *filepath)
{
	int	fd;

	if (!validate_filename(filepath))
		return (false);
	fd = open(filepath, O_RDONLY);
	if (fd < 0)
	{
		print_error(strerror(errno));
		return (false);
	}
	if (!parse_settings(&(cub3d->setting), fd))
	{
		close(fd);
		return (false);
	}
	if (!parse_map(&(cub3d->map), fd))
	{
		cleanup_setting(&(cub3d->setting));
		close(fd);
		return (false);
	}
	close(fd);
	return (true);
}

// Only accepts files with the .cub extension (e.g., map.cub).
// Dotfiles like ".cub" (no basename) are excluded.
static bool	validate_filename(char *filepath)
{
	char	*filename;
	size_t	len;

	filename = ft_strrchr(filepath, '/');
	if (filename != NULL)
		filename++;
	else
		filename = filepath;
	len = ft_strlen(filename);
	if (len <= 4 || ft_strcmp(".cub", filename + len - 4) != 0)
	{
		print_error(ERROR_FILE_EXTENSION);
		return (false);
	}
	return (true);
}

static bool	parse_settings(t_setting *setting, int fd)
{
	char	*line;

	while (is_setting_incomplete(setting))
	{
		line = read_next_setting(fd);
		if (line == NULL)
		{
			cleanup_setting(setting);
			return (false);
		}
		if (!parse_setting_line(setting, line))
		{
			free(line);
			cleanup_setting(setting);
			return (false);
		}
		free(line);
	}
	return (true);
}

static bool	parse_map(t_map *map, int fd)
{
	if (!read_map(map, fd))
		return (false);
	if (!parse_map_elements(map))
	{
		cleanup_map(map);
		return (false);
	}
	return (true);
}
