/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 02:17:46 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/19 02:23:17 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_color	scale_color(double t, t_color color)
{
	return ((t_color){
		.r = t * color.r, \
		.g = t * color.g, \
		.b = t * color.b \
	});
}
