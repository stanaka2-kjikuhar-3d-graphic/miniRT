/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 20:52:21 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/10/31 21:03:23 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"

static enum e_phong_mode	g_phong_mode;

enum e_phong_mode	get_phong_mode(void)
{
	return (g_phong_mode);
}

void	set_phong_mode(enum e_phong_mode mode)
{
	g_phong_mode = mode;
}
