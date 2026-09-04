/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_planar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 21:22:19 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/25 21:25:22 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "object.h"

bool	is_planar_primitive(enum e_primitive_type type)
{
	return (type == UNIT_PLANE || type == UNIT_DISC || type == INFINITE_PLANE);
}
