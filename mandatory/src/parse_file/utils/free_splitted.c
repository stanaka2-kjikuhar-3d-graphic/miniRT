/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_splitted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 23:03:55 by stanaka2          #+#    #+#             */
/*   Updated: 2026/03/15 23:31:20 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_splitted(char **splitted)
{
	size_t	i;

	i = 0;
	if (splitted)
	{
		while (splitted[i] != NULL)
		{
			free(splitted[i]);
			i++;
		}
		free(splitted);
	}
}
