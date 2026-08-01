/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_paraboloid_intersection.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 05:59:09 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/31 20:59:39 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "ray.h"

#include "../object_private.h"

float	calc_paraboloid_intersection(\
	t_paraboloid const *paraboloid, t_ray const *ray)
{
	t_quadric	quad;

	paraboloid_to_quadric(paraboloid, &quad);
	return (calc_quadric_intersection(&quad, ray));
}
