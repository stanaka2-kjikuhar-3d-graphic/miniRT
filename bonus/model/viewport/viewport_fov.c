/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport_fov.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 06:26:10 by stanaka2          #+#    #+#             */
/*   Updated: 2026/11/02 06:53:18 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>

#include "ft_math.h"

#include "viewport.h"

#include "./viewport_private.h"

void	change_viewport_fov(float fov)
{
	t_viewport	*viewport;

	viewport = get_mutable_viewport();
	viewport->half_size.width = tanf(fov * (float)DEG_TO_RAD * 0.5f);
	viewport->half_size.height \
		= viewport->half_size.width / viewport->aspect_ratio;
}
