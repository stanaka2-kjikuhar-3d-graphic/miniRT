/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_material.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 02:04:59 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/03 04:29:34 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>

#include "object.h"
#include "config.h"

void	init_material(t_material *material)
{
	material->pattern_type = PATTERN_SOLID;
	material->albedo = (t_color){0.5f, 0.5f, 0.5f};
	material->texture = NULL;
	material->checkerboard.color1 = (t_color){0.0f, 0.0f, 0.0f};
	material->checkerboard.color2 = (t_color){1.0f, 1.0f, 1.0f};
	material->metalness = false;
	material->shininess = SHININESS;
}
