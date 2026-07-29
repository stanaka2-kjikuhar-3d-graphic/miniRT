/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 18:01:40 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/29 18:25:56 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "ft_string.h"
#include "ft_error_private.h"

#define ERROR_STRING_CAPACITY 1024

static char	g_error_string[ERROR_STRING_CAPACITY];

void	set_error_string(char const *error_string)
{
	size_t	len;

	len = ft_strlcpy(g_error_string, error_string, ERROR_STRING_CAPACITY);
	if (len >= ERROR_STRING_CAPACITY)
		ft_strlcpy(g_error_string + ERROR_STRING_CAPACITY - 4, "...", 4);
}

void	set_error_strings(char const **error_strings)
{
	size_t	i;
	size_t	len;

	len = 0;
	i = 0;
	g_error_string[0] = '\0';
	while (error_strings[i] != NULL)
	{
		if (i != 0)
			ft_strlcat(g_error_string, " ", ERROR_STRING_CAPACITY);
		len = ft_strlcat(g_error_string, error_strings[i], \
							ERROR_STRING_CAPACITY);
		++i;
	}
	if (len >= ERROR_STRING_CAPACITY)
		ft_strlcpy(g_error_string + ERROR_STRING_CAPACITY - 4, "...", 4);
}

char const	*get_error_string(void)
{
	return (g_error_string);
}
