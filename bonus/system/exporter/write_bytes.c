/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_bytes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 23:40:00 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/11/03 23:40:00 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>
#include <unistd.h>

#include "./exporter_private.h"

bool	write_bytes(int fd, char const *buf, size_t size)
{
	ssize_t	written;

	while (size > 0)
	{
		written = write(fd, buf, size);
		if (written <= 0)
			return (false);
		buf += written;
		size -= (size_t)written;
	}
	return (true);
}
