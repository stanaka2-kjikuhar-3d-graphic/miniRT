/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 18:01:40 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/31 03:03:16 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "ft_string.h"

#define ERROR_LINE_CAPACITY 1024

static char		g_error_line[ERROR_LINE_CAPACITY];
static size_t	g_error_line_number;

void	set_error_line(size_t line_number, char const *line)
{
	size_t	len;

	g_error_line_number = line_number;
	len = ft_strlcpy(g_error_line, line, ERROR_LINE_CAPACITY);
	if (len >= ERROR_LINE_CAPACITY)
		ft_strlcpy(g_error_line + ERROR_LINE_CAPACITY - 4, "...", 4);
}

size_t	get_error_line_number(void)
{
	return (g_error_line_number);
}

char const	*get_error_line(void)
{
	return (g_error_line);
}
