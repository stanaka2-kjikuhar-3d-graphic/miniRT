/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 16:29:03 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/29 01:44:41 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_mlx_private.h"

void	ft_mlx_destroy(void)
{
	cleanup_texture_dict();
	cleanup_images();
	cleanup_window();
	cleanup_mlx_connection();
}
