/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_radiance_private.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 14:40:41 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/12 14:46:35 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_RADIANCE_PRIVATE_H
# define LIGHT_RADIANCE_PRIVATE_H

# include "light.h"

void	set_dist_attenuation(t_dist_attenuation *attenuation, float range);

#endif
