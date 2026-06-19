/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 20:28:56 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/19 23:51:35 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stddef.h>

#include "mlx.h"

#include "ft_mlx.h"
#include "drawer.h"

int	draw_hook(void *param)
{
	static struct timeval	last_time_stamp;
	struct timeval			time_stamp;

	(void)param;
	gettimeofday(&time_stamp, NULL);
	if (time_stamp.tv_sec > last_time_stamp.tv_sec)
	{
		drawer();
		last_time_stamp = time_stamp;
	}
	return (0);
}
