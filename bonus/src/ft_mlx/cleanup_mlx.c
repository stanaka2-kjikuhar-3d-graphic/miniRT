/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 05:39:44 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/29 06:00:46 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_mlx_private.h"

void	cleanup_mlx(void)
{
	cleanup_texture_dict();
	cleanup_images();
	cleanup_window();
	cleanup_mlx_connection();
}
