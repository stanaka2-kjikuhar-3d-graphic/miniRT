/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 22:37:00 by stanaka2          #+#    #+#             */
/*   Updated: 2026/03/11 02:19:18 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cleanup_map(t_map *map)
{
	int	i;

	if (map->data != NULL)
	{
		i = 0;
		while (i < map->row_size)
		{
			free(map->data[i]);
			i++;
		}
		free(map->data);
	}
	free(map->col_size);
}
