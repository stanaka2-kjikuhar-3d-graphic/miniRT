/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release_hook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 20:31:05 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/19 21:03:36 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h>

#include "mlx.h"

#include "ft_mlx.h"

int	key_release_hook(int keycode, void *param)
{
	(void)param;
	if (keycode == XK_Escape)
		mlx_loop_end(get_mlx_ptr());
	return (0);
}
