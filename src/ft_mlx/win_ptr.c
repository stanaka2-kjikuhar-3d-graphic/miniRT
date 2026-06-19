/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_ptr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 15:26:47 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/19 21:03:11 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "mlx.h"

#include "ft_error.h"
#include "ft_mlx.h"

#include "./ft_mlx_private.h"

static void	*g_win_ptr;

void	*get_win_ptr(void)
{
	return (g_win_ptr);
}

bool	create_window(int width, int height, char *title)
{
	g_win_ptr = mlx_new_window(get_mlx_ptr(), width, height, title);
	if (g_win_ptr == NULL)
	{
		print_error(ERROR_MLX_WINDOW);
		return (false);
	}
	return (true);
}

void	cleanup_window(void)
{
	if (g_win_ptr != NULL)
	{
		mlx_destroy_window(get_mlx_ptr(), g_win_ptr);
		g_win_ptr = NULL;
	}
}
