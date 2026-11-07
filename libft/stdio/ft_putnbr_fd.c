/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:23:13 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/27 07:33:14 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ft_stdio.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;

	num = (unsigned int)n;
	if (n < 0)
	{
		num = (unsigned int)((-(n + 1)) + 1);
		write(fd, "-", 1);
	}
	if (num >= 10)
		ft_putnbr_fd(num / 10, fd);
	ft_putchar_fd("0123456789"[num % 10], fd);
}
