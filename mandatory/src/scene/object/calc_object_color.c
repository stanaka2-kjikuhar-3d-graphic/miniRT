/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_object_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 02:28:56 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/05 22:55:10 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "color.h"

#include "./object_private.h"

t_color	calc_object_color(t_object const *object)
{
	return (object->albedo);
}
