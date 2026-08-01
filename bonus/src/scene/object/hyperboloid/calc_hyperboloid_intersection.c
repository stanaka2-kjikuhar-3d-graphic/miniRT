/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_hyperboloid_intersection.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 06:40:18 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/31 21:30:00 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "ray.h"

#include "../object_private.h"

float	calc_hyperboloid_intersection(\
	t_hyperboloid const *hyperboloid, t_ray const *ray)
{
	t_quadric	quad;

	hyperboloid_to_quadric(hyperboloid, &quad);
	return (calc_quadric_intersection(&quad, ray));
}
