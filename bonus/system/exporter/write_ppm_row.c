/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_ppm_row.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 23:40:00 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/11/03 23:40:00 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>

#include "config.h"
#include "vector.h"
#include "window_buffer.h"

#include "./exporter_private.h"

// ウィンドウバッファの画素は 0x00RRGGBB で入っている前提で3バイトに詰める
bool	write_ppm_row(int fd, int y)
{
	static char		row[WINDOW_WIDTH * 3];
	unsigned int	pixel;
	int				x;

	x = 0;
	while (x < WINDOW_WIDTH)
	{
		pixel = get_window_buffer_pixel(MAIN_WINDOW_BUFFER, ivec2(x, y));
		row[x * 3] = (char)((pixel >> 16) & 0xff);
		row[x * 3 + 1] = (char)((pixel >> 8) & 0xff);
		row[x * 3 + 2] = (char)(pixel & 0xff);
		++x;
	}
	return (write_bytes(fd, row, sizeof(row)));
}
