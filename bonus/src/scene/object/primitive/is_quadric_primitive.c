/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_quadric_primitive.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 17:22:59 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/29 17:25:27 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "object.h"

bool	is_quadric_primitive(enum e_primitive_type type)
{
	return (type == UNIT_SPHERE || type == UNIT_CYLINDER \
		|| type == UNIT_CONE || type == UNIT_HYPERBOLOID \
		|| type == UNIT_PARABOLOID);
}
