/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 18:01:40 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/26 21:06:12 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static char const	*g_log_line;
static size_t		g_log_line_number;

void	set_log_line(size_t line_number, char const *line)
{
	g_log_line_number = line_number;
	g_log_line = line;
}

size_t	get_log_line_number(void)
{
	return (g_log_line_number);
}

char const	*get_log_line(void)
{
	return (g_log_line);
}
