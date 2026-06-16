/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 17:32:12 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/17 00:07:57 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "ft_mlx.h"
#include "phong_reflection_model.h"

#ifndef DEBUG

int	expose_hook(void *param)
{
	(void)param;
	phong_reflection_model();
	mlx_put_image_to_window(\
		get_mlx_ptr(), get_win_ptr(), get_image(IMG_WINDOW)->ptr, 0, 0);
	return (0);
}

#else

int	expose_hook(void *param)
{
	(void)param;
	mlx_loop_end(get_mlx_ptr());
	return (0);
}

#endif