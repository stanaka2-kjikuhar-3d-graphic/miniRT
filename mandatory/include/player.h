/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 14:22:57 by stanaka2          #+#    #+#             */
/*   Updated: 2026/03/12 17:31:07 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "type.h"

struct s_player
{
	t_dvec2	pos;
	t_dvec2	dir;
	t_dvec2	plane;
	double	fov;
};

#endif