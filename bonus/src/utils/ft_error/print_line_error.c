/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 23:55:59 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/26 00:41:28 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>

#include "ft_string.h"
#include "ft_stdio.h"

#define ERROR_LINE_CAPACITY 1024

static size_t	g_error_line_no;
static char		g_error_line_str[ERROR_LINE_CAPACITY];

void	set_error_line_no(size_t line_no)
{
	g_error_line_no = line_no;
}

void	set_error_line_str(char const *line_str)
{
	size_t	len;

	len = ft_strlcpy(g_error_line_str, line_str, ERROR_LINE_CAPACITY);
	if (len >= ERROR_LINE_CAPACITY)
		ft_strlcpy(g_error_line_str + ERROR_LINE_CAPACITY - 4, "...", 4);
}

void	set_error_line_multi_str(char const **line_strs)
{
	size_t	i;
	size_t	len;

	len = 0;
	i = 0;
	g_error_line_str[0] = '\0';
	while (line_strs[i] != NULL)
	{
		if (i != 0)
			ft_strlcat(g_error_line_str, " ", ERROR_LINE_CAPACITY);
		len = ft_strlcat(g_error_line_str, line_strs[i], ERROR_LINE_CAPACITY);
		++i;
	}
	if (len >= ERROR_LINE_CAPACITY)
		ft_strlcpy(g_error_line_str + ERROR_LINE_CAPACITY - 4, "...", 4);
}

void	print_line_error(char const *msg)
{
	ft_dprintf(STDERR_FILENO, "Error\n");
	ft_dprintf(STDERR_FILENO, "line %zu: %s\n", \
				g_error_line_no, g_error_line_str);
	ft_dprintf(STDERR_FILENO, "%s\n", msg);
}

void	print_line_error_hint(char const *msg, char const *hint)
{
	ft_dprintf(STDERR_FILENO, "Error\n");
	ft_dprintf(STDERR_FILENO, "line %zu: %s\n", \
				g_error_line_no, g_error_line_str);
	ft_dprintf(STDERR_FILENO, "%s\n", msg);
	ft_dprintf(STDERR_FILENO, "%s\n", hint);
}
