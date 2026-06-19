/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_object_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 02:28:56 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/19 02:31:52 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "color.h"

t_color	get_object_color(t_object const *object)
{
	if (object->type == OBJ_SPHERE)
		return (object->sphere.color);
	else if (object->type == OBJ_PLANE)
		return (object->plane.color);
	else if (object->type == OBJ_CYLINDER)
		return (object->cylinder.color);
	else if (object->type == OBJ_CIRCLE)
		return (object->circle.color);
	return ((t_color){0, 0, 0});
}
