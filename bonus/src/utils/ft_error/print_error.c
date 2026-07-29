/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 21:20:43 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/29 17:40:47 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>

#include "ft_stdio.h"

void	print_error(char const *msg)
{
	ft_dprintf(STDERR_FILENO, "Error\n");
	ft_dprintf(STDERR_FILENO, "%s\n", msg);
}

void	print_argument_error(char const *program_name)
{
	ft_dprintf(STDERR_FILENO, "Error\n");
	ft_dprintf(STDERR_FILENO, "USAGE: %s *.rt\n", program_name);
}

void	print_texture_error(char const *path, char const *msg)
{
	ft_dprintf(STDERR_FILENO, "Error\n");
	if (path != NULL && *path != '\0')
		ft_dprintf(STDERR_FILENO, "%s\n", path);
	ft_dprintf(STDERR_FILENO, "%s\n", msg);
}
