/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_dist_attenuation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 20:31:09 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/01 20:32:51 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

/*
https://wiki.ogre3d.org/Light+Attenuation+Shortcut
*/
float	calc_dist_attenuation(t_dist_attenuation const *attenuation, float dist)
{
	return (1.0f / (attenuation->constant \
					+ attenuation->linear * dist \
					+ attenuation->quadratic * dist * dist));
}
