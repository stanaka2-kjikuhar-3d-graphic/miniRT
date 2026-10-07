/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ior.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 21:15:11 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/10/07 21:33:25 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "ft_error.h"

#include "../parser_private.h"

bool	parse_ior(char const *element, void *value)
{
	float *const	ior = (float *)value;

	if (!parse_float(element, ior))
		return (false);
	if (*ior < 0.0f)
	{
		print_field_error(ERROR_OUT_OF_RANGE, HINT_NON_NEGATIVE);
		return (false);
	}
	return (true);
}
