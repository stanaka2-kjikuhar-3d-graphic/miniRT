/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_texture_error.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 18:33:12 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/05 21:02:34 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>

#include "ft_stdio.h"

void	print_texture_error(char const *path, char const *msg)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	if (path != NULL && *path != '\0')
	{
		ft_putstr_fd((char *)path, STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
	}
	ft_putstr_fd((char *)msg, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}
