/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_hyperboloid_intersection.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 06:40:18 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/06 21:33:31 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "ray.h"

#include "../object_private.h"

float	calc_hyperboloid_intersection(\
	t_hyperboloid const *hyperboloid, t_ray const *ray)
{
	return (calc_quadric_intersection(&(hyperboloid->quadric), ray));
}
