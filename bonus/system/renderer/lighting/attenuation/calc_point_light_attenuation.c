/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_point_light_attenuation.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 17:26:53 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/04 21:27:20 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

#include "../lighting_private.h"

float	calc_point_light_attenuation(t_point_light const *light, float dist)
{
	return (calc_dist_attenuation(&(light->attenuation), dist));
}
