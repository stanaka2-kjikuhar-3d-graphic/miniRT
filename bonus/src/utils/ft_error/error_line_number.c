/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_line_number.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 17:58:11 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/29 17:59:36 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "ft_error_private.h"

static size_t	g_line_number;

void	set_error_line_number(size_t line_number)
{
	g_line_number = line_number;
}

size_t	get_error_line_number(void)
{
	return (g_line_number);
}
