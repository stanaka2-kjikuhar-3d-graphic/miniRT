/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_shininess.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 03:12:52 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/03 03:45:13 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "ft_error.h"

#include "../parser_private.h"

bool	parse_shininess(char const *element, float *shininess)
{
	if (!parse_float(element, shininess))
		return (false);
	if (*shininess < 0.0f)
	{
		print_error(ERROR_SHININESS_RANGE);
		return (false);
	}
	return (true);
}
