/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_dist_attenuation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 18:45:58 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/01 20:43:48 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

/*
https://wiki.ogre3d.org/Light+Attenuation+Shortcut
*/
void	set_dist_attenuation(t_dist_attenuation *attenuation, float range)
{
	attenuation->range = range;
	attenuation->constant = 1.0f;
	attenuation->linear = 4.5f / range;
	attenuation->quadratic = 75.0f / (range * range);
}
