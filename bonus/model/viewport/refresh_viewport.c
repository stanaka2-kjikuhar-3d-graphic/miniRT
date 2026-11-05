/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_viewport.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 06:48:43 by stanaka2          #+#    #+#             */
/*   Updated: 2026/11/02 06:55:53 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "viewport.h"

#include "./viewport_private.h"

void	refresh_viewport(void)
{
	t_viewport	*viewport;

	viewport = get_mutable_viewport();
	viewport->sample_count = 0;
	viewport->resolution.level = 0;
}
