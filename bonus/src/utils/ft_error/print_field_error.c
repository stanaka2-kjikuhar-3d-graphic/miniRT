/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_field_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 18:30:45 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/29 18:32:00 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>

#include "ft_stdio.h"
#include "ft_error_private.h"

void	print_field_error(char const *msg, char const *hint)
{
	ft_dprintf(STDERR_FILENO, "Error\n");
	ft_dprintf(STDERR_FILENO, "line %zu: %s\n", \
				get_error_line_number(), get_error_string());
	ft_dprintf(STDERR_FILENO, "%s: %s\n", get_error_field(), msg);
	if (hint != NULL)
		ft_dprintf(STDERR_FILENO, "USAGE: %s\n", hint);
}
