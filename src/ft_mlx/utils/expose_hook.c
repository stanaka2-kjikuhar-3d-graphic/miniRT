/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 17:32:12 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/16 15:15:16 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG

int	expose_hook(void *param)
{
	(void)param;
	return (0);
}

#else

#include "mlx.h"
#include "ft_mlx.h"

int	expose_hook(void *param)
{
	(void)param;
	mlx_loop_end(get_mlx_ptr());
	return (0);
}

#endif