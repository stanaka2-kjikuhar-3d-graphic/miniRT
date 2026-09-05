/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 20:28:56 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/05 22:25:22 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stddef.h>
#include <stdint.h>

#include "mlx.h"

#include "config.h"
#include "renderer.h"

static bool	frame_per_second(void);

int	loop_hook(void *param)
{
	(void)param;
	if (frame_per_second())
		renderer();
	return (0);
}

static bool	frame_per_second(void)
{
	static struct timeval	last;
	struct timeval			now;
	int64_t					elapsed_us;

	gettimeofday(&now, NULL);
	elapsed_us = (now.tv_sec - last.tv_sec) * SEC_TO_USEC \
					+ (now.tv_usec - last.tv_usec);
	if (elapsed_us * FRAME_RATE < SEC_TO_USEC)
		return (false);
	last = now;
	return (true);
}
