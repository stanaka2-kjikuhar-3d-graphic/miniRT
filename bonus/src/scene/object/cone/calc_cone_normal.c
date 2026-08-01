/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_cone_normal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 19:25:57 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/31 18:39:01 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "object.h"
#include "ray.h"

#include "../object_private.h"

t_vec3	calc_cone_normal(\
	t_cone const *cone, t_ray const *ray, t_vec3 point)
{
	t_quadric	quad;

	cone_to_quadric(cone, &quad);
	return (calc_quadric_normal(&quad, ray, point));
}
