/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_paraboloid_normal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 22:43:28 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/06 21:33:43 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "object.h"
#include "ray.h"

#include "../object_private.h"

t_vec3	calc_paraboloid_normal(\
	t_paraboloid const *paraboloid, t_ray const *ray, t_vec3 point)
{
	return (calc_quadric_normal(&(paraboloid->quadric), ray, point));
}
