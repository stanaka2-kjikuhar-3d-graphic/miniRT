/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sample_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 06:17:13 by stanaka2          #+#    #+#             */
/*   Updated: 2026/11/03 06:19:19 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "viewport.h"

#include "./viewport_private.h"

void	set_sample_count(enum e_buffering_mode mode)
{
	if (mode == BUFFERING_OVERWRITE)
		get_mutable_viewport()->sample_count = 1;
	else if (mode == BUFFERING_ACCUMULATE)
		++(get_mutable_viewport()->sample_count);
}
