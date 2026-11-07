/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_viewport_interpolation.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 17:45:39 by stanaka2          #+#    #+#             */
/*   Updated: 2026/11/07 17:50:54 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "viewport.h"

#include "./viewport_private.h"

void	switch_viewport_interpolation(void)
{
	t_viewport	*viewport;

	viewport = get_mutable_viewport();
	if (viewport->resolution.interpolation == NEAREST_INTERPOLATION)
		viewport->resolution.interpolation = BILINEAR_INTERPOLATION;
	else
		viewport->resolution.interpolation = NEAREST_INTERPOLATION;
}
