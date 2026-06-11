/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_splitted.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 00:43:09 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/12 00:47:06 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	count_splitted(char const **splitted)
{
	size_t	count;

	if (splitted == NULL)
		return (0);
	count = 0;
	while (splitted[count] != NULL)
		++count;
	return (count);
}
