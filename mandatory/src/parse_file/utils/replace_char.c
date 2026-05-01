/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:58:25 by stanaka2          #+#    #+#             */
/*   Updated: 2026/03/11 16:02:20 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	replace_char(char *s, char from, char to)
{
	if (s == NULL || from == '\0' || from == to)
		return ;
	while (*s)
	{
		if (*s == from)
			*s = to;
		s++;
	}
}
