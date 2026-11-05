/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 21:09:57 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/11/01 18:02:42 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_mode.h"

static enum e_render_mode	g_render_mode;

enum e_render_mode	get_render_mode(void)
{
	return (g_render_mode);
}

void	set_render_mode(enum e_render_mode mode)
{
	g_render_mode = mode;
}
