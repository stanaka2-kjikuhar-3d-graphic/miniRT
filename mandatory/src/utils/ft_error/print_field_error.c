/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_field_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 18:30:45 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/05 22:20:08 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>

#include "ft_stdio.h"
#include "ft_error_private.h"

void	print_field_error(char const *msg, char const *hint)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd("line ", STDERR_FILENO);
	print_nbr(get_error_line_number(), STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd((char *)get_error_line(), STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	ft_putstr_fd((char *)get_error_field(), STDERR_FILENO);
	ft_putstr_fd(" '", STDERR_FILENO);
	ft_putstr_fd((char *)get_error_token(), STDERR_FILENO);
	ft_putstr_fd("': ", STDERR_FILENO);
	ft_putstr_fd((char *)msg, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	if (hint != NULL)
	{
		ft_putstr_fd("USAGE: ", STDERR_FILENO);
		ft_putstr_fd((char *)hint, STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
	}
}
