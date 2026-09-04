/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_mlx_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 05:38:03 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/29 06:01:22 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "mlx.h"

#include "config.h"
#include "ft_mlx.h"

bool	setup_mlx_window(void)
{
	if (!create_image(IMG_WINDOW, WINDOW_WIDTH, WINDOW_HEIGHT) \
		|| !create_window(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE))
	{
		return (false);
	}
	mlx_clear_window(get_mlx_ptr(), get_win_ptr());
	return (true);
}
