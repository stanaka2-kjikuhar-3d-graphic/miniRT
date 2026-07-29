/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_shininess.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 03:12:52 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/26 00:46:25 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "ft_error.h"

#include "../parser_private.h"

bool	parse_shininess(char const *element, void *value)
{
	float *const	shininess = (float *)value;

	if (!parse_float(element, shininess))
		return (false);
	if (*shininess < 0.0f)
	{
		print_field_error(ERROR_MUST_BE_NON_NEGATIVE, NULL);
		return (false);
	}
	return (true);
}
