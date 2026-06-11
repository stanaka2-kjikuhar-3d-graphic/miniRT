/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_ptr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 14:58:49 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/12 02:31:15 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

#include "mlx.h"
#include "ft_error.h"
#include "ft_error.h"

static void	*g_mlx_ptr;

void	*get_mlx_ptr(void)
{
	return (g_mlx_ptr);
}

bool	create_mlx_connection(void)
{
	g_mlx_ptr = mlx_init();
	if (g_mlx_ptr == NULL)
	{
		print_error(ERROR_MLX_CONNECTION);
		return (false);
	}
	return (true);
}

void	cleanup_mlx_connection(void)
{
	if (g_mlx_ptr != NULL)
	{
		mlx_destroy_display(g_mlx_ptr);
		free(g_mlx_ptr);
		g_mlx_ptr = NULL;
	}
}
