/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_mlx_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 05:38:03 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/18 07:56:03 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "mlx.h"

#include "config.h"
#include "image.h"
#include "window.h"
#include "window_buffer.h"

bool	setup_mlx_window(void)
{
	if (!create_window_buffer(MAIN_WINDOW_BUFFER, WINDOW_WIDTH, WINDOW_HEIGHT) \
		|| !create_window(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE))
	{
		return (false);
	}
	mlx_clear_window(get_mlx_ptr(), get_win_ptr());
	return (true);
}
