/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bvh_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 20:23:03 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/14 00:11:50 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static size_t	g_count;

size_t	get_bvh_count(void)
{
	return (g_count);
}

void	set_bvh_count(size_t count)
{
	g_count = count;
}

void	clear_bvh_count(void)
{
	g_count = 0;
}
