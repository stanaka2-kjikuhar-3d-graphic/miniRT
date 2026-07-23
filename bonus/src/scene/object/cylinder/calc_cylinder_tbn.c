/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_cylinder_tbn.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 19:51:26 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/21 21:40:42 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "vector.h"

t_onb	calc_cylinder_tbn(t_cylinder const *cylinder, t_vec3 normal)
{
	t_onb	tbn;

	tbn.w = normal;
	tbn.v = vec3_scale(-1.0f, cylinder->dir);
	tbn.u = vec3_cross(tbn.w, tbn.v);
	return (tbn);
}
