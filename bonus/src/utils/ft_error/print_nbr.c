/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 20:28:17 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/05 20:31:17 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ft_stdio.h"

ssize_t	print_nbr(size_t nbr, int fd)
{
	ssize_t			ret;
	ssize_t			written_bytes;

	written_bytes = 0;
	if (nbr >= 10)
	{
		ret = print_nbr(nbr / 10, fd);
		if (ret == -1)
			return (-1);
		written_bytes += ret;
	}
	if (ft_putchar_fd_bytes("0123456789"[nbr % 10], fd) == -1)
		return (-1);
	written_bytes++;
	return (written_bytes);
}
