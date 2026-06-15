/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errno.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 12:20:38 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/15 21:39:13 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <unistd.h>

#include "ft_stdio.h"

void	print_errno(void)
{
	char	*msg;

	msg = strerror(errno);
	ft_dprintf(STDERR_FILENO, "Error\n");
	ft_dprintf(STDERR_FILENO, "%s\n", msg);
}
