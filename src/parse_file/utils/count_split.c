/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 07:19:11 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/15 07:19:19 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	count_split(char const **split)
{
	size_t	count;

	if (split == NULL)
		return (0);
	count = 0;
	while (split[count] != NULL)
		++count;
	return (count);
}
