/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_log_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 22:56:20 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/24 00:48:01 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "ft_stdio.h"

bool	print_log_str(char const *s, int fd, bool result)
{
	if (ft_putstr_fd_bytes((char *)s, fd) == -1)
		return (false);
	return (result);
}
