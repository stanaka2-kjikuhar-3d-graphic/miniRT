/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_setting_incomplete.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 10:58:29 by stanaka2          #+#    #+#             */
/*   Updated: 2026/03/11 11:15:58 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_setting_incomplete(t_setting *setting)
{
	return (setting->flags ^ ((1 << SETTING_COUNT) - 1));
}
