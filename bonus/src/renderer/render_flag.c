/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 23:56:22 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/23 23:56:27 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

static bool	g_render_flag;

bool	check_render_flag(void)
{
	return (g_render_flag);
}

void	set_render_flag(bool status)
{
	g_render_flag = status;
}
