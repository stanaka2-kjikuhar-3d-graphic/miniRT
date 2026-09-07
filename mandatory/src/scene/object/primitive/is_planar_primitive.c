/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_planar_primitive.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 21:22:19 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/05 21:43:35 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "object.h"

bool	is_planar_primitive(enum e_primitive_type type)
{
	return (type == UNIT_DISC || type == INFINITE_PLANE);
}
