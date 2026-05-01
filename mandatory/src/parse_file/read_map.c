/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 22:21:55 by stanaka2          #+#    #+#             */
/*   Updated: 2026/03/11 16:03:00 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	read_map_as_list(int fd, t_list **list);
static bool	compute_row_size(t_list *list, t_map *map);
static bool	convert_list_to_array(t_list *list, t_map *map);
static bool	compute_col_size(t_map *map);

bool	read_map(t_map *map, int fd)
{
	t_list	*list;

	list = NULL;
	if (!read_map_as_list(fd, &list) \
		|| !compute_row_size(list, map) \
		|| !convert_list_to_array(list, map))
	{
		ft_lstclear(&list, free);
		return (false);
	}
	ft_lstclear(&list, NULL);
	if (!compute_col_size(map))
	{
		cleanup_map(map);
		return (false);
	}
	return (true);
}

static bool	read_map_as_list(int fd, t_list **list)
{
	char	*line;

	*list = NULL;
	while (true)
	{
		line = get_next_line(fd);
		if (errno)
		{
			print_error(strerror(errno));
			return (false);
		}
		if (line == NULL)
			break ;
		replace_char(line, '\n', '\0');
		if (*list == NULL && line[0] == '\0')
			free(line);
		else if (!ft_lst_push_back(list, line))
		{
			free(line);
			print_error(strerror(errno));
			return (false);
		}
	}
	return (true);
}

static bool	compute_row_size(t_list *list, t_map *map)
{
	size_t	row_size;

	row_size = 0;
	while (list != NULL)
	{
		list = list->next;
		row_size++;
	}
	if (row_size > (size_t)INT_MAX)
	{
		print_error(ERROR_MAP_TOO_LARGE);
		return (false);
	}
	if (row_size == 0)
	{
		print_error(ERROR_MAP_EMPTY);
		return (false);
	}
	map->row_size = row_size;
	return (true);
}

// Transfers ownership of list->content to map->data.
// Caller must use ft_lstclear(&list, NULL) after success.
static bool	convert_list_to_array(t_list *list, t_map *map)
{
	int	row;

	map->data = (char **)malloc(sizeof(char *) * map->row_size);
	if (map->data == NULL)
	{
		print_error(strerror(errno));
		return (false);
	}
	row = 0;
	while (row < map->row_size)
	{
		map->data[row] = list->content;
		list = list->next;
		row++;
	}
	return (true);
}

static bool	compute_col_size(t_map *map)
{
	int		row;
	size_t	len;

	map->col_size = (int *)malloc(sizeof(int) * map->row_size);
	if (map->col_size == NULL)
	{
		print_error(strerror(errno));
		return (false);
	}
	row = 0;
	while (row < map->row_size)
	{
		len = ft_strlen(map->data[row]);
		if ((size_t)INT_MAX < len)
		{
			free(map->col_size);
			map->col_size = NULL;
			print_error(ERROR_MAP_TOO_LARGE);
			return (false);
		}
		map->col_size[row] = (int)len;
		row++;
	}
	return (true);
}
