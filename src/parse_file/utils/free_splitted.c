/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_splitted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 21:36:01 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/06/10 19:41:30 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_splitted(char **splitted)
{
	int	i;

	if (splitted == NULL)
		return ;
	i = 0;
	while (splitted[i] != NULL)
	{
		free(splitted[i++]);
	}
	free(splitted);
}
