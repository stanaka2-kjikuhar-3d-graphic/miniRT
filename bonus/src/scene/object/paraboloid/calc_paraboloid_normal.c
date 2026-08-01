/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_paraboloid_normal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 22:43:28 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/31 20:59:39 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "object.h"
#include "ray.h"

#include "../object_private.h"

t_vec3	calc_paraboloid_normal(\
	t_paraboloid const *paraboloid, t_ray const *ray, t_vec3 point)
{
	t_quadric	quad;

	paraboloid_to_quadric(paraboloid, &quad);
	return (calc_quadric_normal(&quad, ray, point));
}
