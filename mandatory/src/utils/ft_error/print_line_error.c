/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 23:55:59 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/29 18:32:08 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>

#include "ft_stdio.h"
#include "ft_error_private.h"

void	print_line_error(char const *msg, char const *hint)
{
	ft_dprintf(STDERR_FILENO, "Error\n");
	ft_dprintf(STDERR_FILENO, "line %zu: %s\n", \
				get_error_line_number(), get_error_line());
	ft_dprintf(STDERR_FILENO, "%s\n", msg);
	if (hint != NULL)
		ft_dprintf(STDERR_FILENO, "USAGE: %s\n", hint);
}
