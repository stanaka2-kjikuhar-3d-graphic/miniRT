/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_plane_tbn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 19:26:01 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/21 20:28:33 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "vector.h"

t_onb	calc_plane_tbn(t_plane const *plane, t_vec3 normal)
{
	t_onb	tbn;

	tbn.w = normal;
	tbn.u = plane->onb.u;
	tbn.v = vec3_cross(tbn.w, tbn.u);
	return (tbn);
}
