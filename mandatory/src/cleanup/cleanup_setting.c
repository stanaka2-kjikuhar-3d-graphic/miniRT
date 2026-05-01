/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_setting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 00:01:15 by stanaka2          #+#    #+#             */
/*   Updated: 2026/03/11 00:03:11 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cleanup_setting(t_setting *setting)
{
	free(setting->north_texture);
	free(setting->south_texture);
	free(setting->west_texture);
	free(setting->east_texture);
}
