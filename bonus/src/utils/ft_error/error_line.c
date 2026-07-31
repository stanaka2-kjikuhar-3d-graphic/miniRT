/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 18:01:40 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/31 14:47:24 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "ft_string.h"

static char		*g_error_line;
static size_t	g_error_line_number;

void	set_error_line(size_t line_number, char const *line)
{
	g_error_line_number = line_number;
	g_error_line = line;
}

size_t	get_error_line_number(void)
{
	return (g_error_line_number);
}

char const	*get_error_line(void)
{
	return (g_error_line);
}
