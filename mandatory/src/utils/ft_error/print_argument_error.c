/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argument_error.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 18:33:19 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/05 21:00:50 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ft_stdio.h"

void	print_argument_error(char const *program_name)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd("USAGE: ", STDERR_FILENO);
	ft_putstr_fd((char *)program_name, STDERR_FILENO);
	ft_putstr_fd(" *.rt\n", STDERR_FILENO);
}
