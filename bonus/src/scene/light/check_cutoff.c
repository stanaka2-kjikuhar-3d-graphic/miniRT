/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cutoff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 22:27:54 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/06 21:32:32 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "config.h"
#include "color.h"
#include "light.h"

bool	check_cutoff(t_color radiance, float attenuation)
{
	return ((radiance.r + radiance.g + radiance.b) / (3.0f * attenuation) \
				< LIGHT_COLOR_CUTOFF);
}
