/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_log_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 20:28:17 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/26 22:26:11 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <sys/types.h>
#include <stdbool.h>

#include "ft_stdio.h"

bool	print_log_nbr(size_t nbr, int fd, bool result)
{
	ssize_t	ret;

	if (nbr >= 10)
	{
		ret = print_log_nbr(nbr / 10, fd, result);
		if (ret == -1)
			return (false);
	}
	if (ft_putchar_fd_bytes("0123456789"[nbr % 10], fd) == -1)
		return (false);
	return (result);
}
