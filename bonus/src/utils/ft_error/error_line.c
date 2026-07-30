/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_line.c                                       :+:      :+:    :+:   */
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

#define ERROR_LINE_CAPACITY 1024

static char	g_error_line[ERROR_LINE_CAPACITY];

void	set_error_line(char const *line)
{
	size_t	len;

	len = ft_strlcpy(g_error_line, line, ERROR_LINE_CAPACITY);
	if (len >= ERROR_LINE_CAPACITY)
		ft_strlcpy(g_error_line + ERROR_LINE_CAPACITY - 4, "...", 4);
}

char const	*get_error_line(void)
{
	return (g_error_line);
}
