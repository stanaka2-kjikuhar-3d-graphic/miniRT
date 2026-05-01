/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 22:18:36 by stanaka2          #+#    #+#             */
/*   Updated: 2026/03/12 18:02:09 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool		enqueue_neighbors_pos(t_list **queue, t_map *map, t_ivec2 pos);
static bool		enqueue_pos(t_list **queue, t_map *map, int x, int y);
static t_ivec2	dequeue_pos(t_list **queue);
static bool		is_connected_map(t_map *map);

// マップの連結性が不要な場合は使用しない（課題解釈による）
bool	flood_fill(t_map *map)
{
	t_list	*queue;
	t_ivec2	pos;

	queue = NULL;
	pos = ivec2(map->player_pos.x, map->player_pos.y);
	if (!enqueue_pos(&queue, map, pos.x, pos.y))
		return (false);
	while (queue != NULL)
	{
		pos = dequeue_pos(&queue);
		if (!enqueue_neighbors_pos(&queue, map, pos))
		{
			ft_lstclear(&queue, free);
			return (false);
		}
	}
	return (is_connected_map(map));
}

static bool	enqueue_neighbors_pos(t_list **queue, t_map *map, t_ivec2 pos)
{
	if (!enqueue_pos(queue, map, pos.x - 1, pos.y) \
		|| !enqueue_pos(queue, map, pos.x + 1, pos.y) \
		|| !enqueue_pos(queue, map, pos.x, pos.y - 1) \
		|| !enqueue_pos(queue, map, pos.x, pos.y + 1))
	{
		return (false);
	}
	return (true);
}

// Visited flag: negative value means already enqueued
static bool	enqueue_pos(t_list **queue, t_map *map, int x, int y)
{
	t_ivec2	*store;

	if (!is_map_element(map, x, y))
		return (true);
	map->data[y][x] = -map->data[y][x];
	store = (t_ivec2 *)malloc(sizeof(t_ivec2));
	if (store == NULL)
	{
		print_error(strerror(errno));
		return (false);
	}
	*store = ivec2(x, y);
	if (!ft_lst_push_back(queue, store))
	{
		free(store);
		print_error(strerror(errno));
		return (false);
	}
	return (true);
}

static t_ivec2	dequeue_pos(t_list **queue)
{
	t_ivec2	pos;
	t_ivec2	*store;

	store = (t_ivec2 *)ft_lst_pop_front(queue);
	pos = *store;
	free(store);
	return (pos);
}

// Unvisited elements mean disconnected map; restore visited ones
static bool	is_connected_map(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->row_size)
	{
		x = 0;
		while (x < map->col_size[y])
		{
			if (map->data[y][x] == MAP_FLOOR || map->data[y][x] == MAP_WALL)
			{
				print_error(ERROR_MAP_NOT_CONNECTED);
				return (false);
			}
			if (map->data[y][x] == -MAP_FLOOR || map->data[y][x] == -MAP_WALL)
				map->data[y][x] = -map->data[y][x];
			x++;
		}
		y++;
	}
	return (true);
}
