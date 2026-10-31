/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 21:09:57 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/10/31 21:18:00 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"

static enum e_render_mode	g_render_mode;

enum e_render_mode	get_render_mode(void)
{
	return (g_render_mode);
}

void	set_render_mode(enum e_render_mode mode)
{
	g_render_mode = mode;
}
