/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_cone_intersection.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 02:41:38 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/06 21:33:11 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "ray.h"

#include "../object_private.h"

float	calc_cone_intersection(t_cone const *cone, t_ray const *ray)
{
	return (calc_quadric_intersection(&(cone->quadric), ray));
}
