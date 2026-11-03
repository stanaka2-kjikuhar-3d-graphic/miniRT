/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_ppm_header.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 23:40:00 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/11/03 23:40:00 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>

#include "ft_stdio.h"

#include "config.h"

#include "./exporter_private.h"

bool	write_ppm_header(int fd)
{
	char	header[64];
	int		len;

	len = ft_snprintf(header, sizeof(header), "P6\n%d %d\n%d\n", \
						WINDOW_WIDTH, WINDOW_HEIGHT, PPM_MAX_VALUE);
	if (len < 0 || (size_t)len >= sizeof(header))
		return (false);
	return (write_bytes(fd, header, (size_t)len));
}
