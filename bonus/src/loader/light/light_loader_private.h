/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_loader_private.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 22:40:58 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/15 23:19:01 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_LOADER_PRIVATE_H
# define LIGHT_LOADER_PRIVATE_H

# include <stdbool.h>

# include "light.h"

void	set_dist_attenuation(t_dist_attenuation *attenuation, float range);

#endif
