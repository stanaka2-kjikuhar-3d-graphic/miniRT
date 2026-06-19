/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 21:23:48 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/19 21:29:29 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

static bool	g_draw_flag;

bool	check_draw_flag(void)
{
	return (g_draw_flag);
}

void	set_draw_flag(bool status)
{
	g_draw_flag = status;
}
