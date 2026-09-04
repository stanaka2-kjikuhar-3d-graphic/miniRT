/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pattern_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 19:38:30 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/02 01:29:10 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "object.h"

#include "../parser_private.h"

enum e_pattern_type	get_pattern_type(char const **optional_elements)
{
	enum e_pattern_type	type;
	size_t				i;

	type = PATTERN_SOLID;
	i = 0;
	while (optional_elements[i] != NULL)
	{
		if (is_option_id("texture", optional_elements[i]))
			type = PATTERN_TEXTURE;
		else if (is_option_id("checker_color1", optional_elements[i]) \
			|| is_option_id("checker_color2", optional_elements[i]) \
			|| is_option_id("checker_count_u", optional_elements[i]) \
			|| is_option_id("checker_count_v", optional_elements[i]))
		{
			type = PATTERN_CHECKER;
		}
		++i;
	}
	return (type);
}
