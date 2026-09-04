/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 05:39:44 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/16 19:12:05 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_mlx_private.h"

void	cleanup_mlx(void)
{
	cleanup_textures();
	cleanup_images();
	cleanup_window();
	cleanup_mlx_connection();
}
