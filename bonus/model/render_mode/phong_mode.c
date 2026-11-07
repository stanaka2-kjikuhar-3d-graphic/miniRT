/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 20:52:21 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/11/01 18:02:49 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_mode.h"

static enum e_phong_mode	g_phong_mode;

enum e_phong_mode	get_phong_mode(void)
{
	return (g_phong_mode);
}

void	set_phong_mode(enum e_phong_mode mode)
{
	g_phong_mode = mode;
}
