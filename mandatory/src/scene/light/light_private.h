/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_private.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 15:35:16 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/16 00:36:54 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_PRIVATE_H
# define LIGHT_PRIVATE_H

# include <stdbool.h>

# include "light.h"

bool	create_light(t_light const *light);
void	set_dist_attenuation(t_dist_attenuation *attenuation, float range);
float	calc_dist_attenuation(\
			t_dist_attenuation const *attenuation, float dist);

#endif
