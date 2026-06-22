/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 21:38:45 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/22 20:46:47 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

#include "ft_mlx.h"
#include "drawer.h"

#include "./drawer_private.h"

void	drawer(void)
{
	if (check_draw_flag())
	{
		phong();
		mlx_put_image_to_window(\
			get_mlx_ptr(), get_win_ptr(), get_image(IMG_WINDOW)->ptr, 0, 0);
		set_draw_flag(false);
	}
}
