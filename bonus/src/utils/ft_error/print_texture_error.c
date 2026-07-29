/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_texture_error.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 18:33:12 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/29 18:33:49 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>

#include "ft_stdio.h"

void	print_texture_error(char const *path, char const *msg)
{
	ft_dprintf(STDERR_FILENO, "Error\n");
	if (path != NULL && *path != '\0')
		ft_dprintf(STDERR_FILENO, "%s\n", path);
	ft_dprintf(STDERR_FILENO, "%s\n", msg);
}
