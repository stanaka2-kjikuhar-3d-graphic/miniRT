/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_optional_fields.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 22:07:00 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/02 02:03:52 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "config.h"

#include "../parser_private.h"

static const t_optional_field	g_optional_fields[OPTIONAL_FIELD_COUNT] = {\
	[OPTIONAL_TEXTURE] = {NULL, "texture", parse_texture, \
		"texture=file.xpm", FIELD_IMAGE, {.image = NULL}}, \
	[OPTIONAL_CHECKER_COLOR1] = {NULL, "checker_color1", parse_color, \
		"checker_color1=R,G,B [0 <= R,G,B <= 255]", \
		FIELD_COLOR, {.color = {0.0f, 0.0f, 0.0f}}}, \
	[OPTIONAL_CHECKER_COLOR2] = {NULL, "checker_color2", parse_color, \
		"checker_color2=R,G,B [0 <= R,G,B <= 255]", \
		FIELD_COLOR, {.color = {1.0f, 1.0f, 1.0f}}}, \
	[OPTIONAL_BUMP_MAP] = {NULL, "bump_map", parse_texture, \
		"bump_map=file.xpm", FIELD_IMAGE, {.image = NULL}}, \
	[OPTIONAL_NORMAL_MAP] = {NULL, "normal_map", parse_texture, \
		"normal_map=file.xpm", FIELD_IMAGE, {.image = NULL}}, \
	[OPTIONAL_DIRECTX_NORMAL_MAP] = {NULL, "directx_normal_map", parse_bool, \
		"directx_normal_map=true/false", FIELD_BOOL, {.boolean = false}}, \
	[OPTIONAL_BUMP_STRENGTH] = {NULL, "bump_strength", parse_size, \
		"bump_strength=x [0.0 < x]", FIELD_FLOAT, {.number = BUMP_STRENGTH}}, \
	[OPTIONAL_METALNESS] = {NULL, "metalness", parse_bool, \
		"metalness=true/false", FIELD_BOOL, {.boolean = false}}, \
	[OPTIONAL_SHININESS] = {NULL, "shininess", parse_shininess, \
		"shininess=x [0.0 <= x]", FIELD_FLOAT, {.number = SHININESS}}, \
	[OPTIONAL_PATTERN_SIZE] = {NULL, "pattern_size", parse_size, \
		"pattern_size=x [0.0 < x]", FIELD_FLOAT, {.number = PATTERN_SIZE}}, \
	[OPTIONAL_CHECKER_COUNT_U] = {NULL, "checker_count_u", \
		parse_checker_count, "checker_count_u=n [2 <= n <= 1024]", \
		FIELD_INT, {.integer = CHECKER_COUNT}}, \
	[OPTIONAL_CHECKER_COUNT_V] = {NULL, "checker_count_v", \
		parse_checker_count, "checker_count_v=n [2 <= n <= 1024]", \
		FIELD_INT, {.integer = CHECKER_COUNT}}, \
	[OPTIONAL_CHECKER_COUNT_U_EVEN] = {NULL, "checker_count_u", \
		parse_checker_count_even, \
		"checker_count_u=n [2 <= n <= 1024, even number]", \
		FIELD_INT, {.integer = CHECKER_COUNT}}, \
	[OPTIONAL_CHECKER_COUNT_V_EVEN] = {NULL, "checker_count_v", \
		parse_checker_count_even, \
		"checker_count_v=n [2 <= n <= 1024, even number]", \
		FIELD_INT, {.integer = CHECKER_COUNT}} \
};

void	init_optional_fields(t_optional_field *fields)
{
	size_t	i;

	i = 0;
	while (i < OPTIONAL_FIELD_COUNT)
	{
		fields[i] = g_optional_fields[i];
		++i;
	}
}
