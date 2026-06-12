/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 21:36:01 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/06/12 14:15:25 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	free_split(char **split)
{
	size_t	i;

	if (split == NULL)
		return ;
	i = 0;
	while (split[i] != NULL)
	{
		free(split[i++]);
	}
	free(split);
}
