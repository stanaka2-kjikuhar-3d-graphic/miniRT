/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 21:56:59 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/10/04 22:12:30 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phong.h"

static enum e_phong_mode	g_phong_mode;

enum e_phong_mode	get_phong_mode(void)
{
	return (g_phong_mode);
}

void	set_phong_mode(enum e_phong_mode mode)
{
	g_phong_mode = mode;
}
