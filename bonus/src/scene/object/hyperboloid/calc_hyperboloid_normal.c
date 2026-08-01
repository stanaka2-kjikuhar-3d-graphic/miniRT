/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_hyperboloid_normal.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 23:24:37 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/31 21:30:00 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "object.h"
#include "ray.h"

#include "../object_private.h"

t_vec3	calc_hyperboloid_normal(\
	t_hyperboloid const *hyperboloid, t_ray const *ray, t_vec3 point)
{
	t_quadric	quad;

	hyperboloid_to_quadric(hyperboloid, &quad);
	return (calc_quadric_normal(&quad, ray, point));
}
