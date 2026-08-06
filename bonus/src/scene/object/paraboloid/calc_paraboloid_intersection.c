/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_paraboloid_intersection.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 05:59:09 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/06 21:33:41 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "ray.h"

#include "../object_private.h"

float	calc_paraboloid_intersection(\
	t_paraboloid const *paraboloid, t_ray const *ray)
{
	return (calc_quadric_intersection(&(paraboloid->quadric), ray));
}
