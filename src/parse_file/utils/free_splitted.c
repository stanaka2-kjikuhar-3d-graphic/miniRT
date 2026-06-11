/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_splitted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 21:36:01 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/06/12 00:40:33 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
