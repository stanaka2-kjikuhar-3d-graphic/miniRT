/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_cone_intersection.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 02:41:38 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/31 18:39:00 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "ray.h"

#include "../object_private.h"

float	calc_cone_intersection(t_cone const *cone, t_ray const *ray)
{
	t_quadric	quad;

	cone_to_quadric(cone, &quad);
	return (calc_quadric_intersection(&quad, ray));
}
