/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtod_set_exponent.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 20:01:36 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/14 20:03:06 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "../ft_strtod_internal.h"

static bool	is_normalized(t_to_double *to_double);

void	strtod_set_exponent(t_to_double *to_double)
{
	to_double->exp = DBL_EMAX;
	if (to_double->lsb == NULL)
		to_double->exp = 0;
	else if (to_double->lsb <= to_double->ones_digit)
	{
		while (to_double->exp < 2047 && !is_normalized(to_double))
		{
			if (*(to_double->end) % 2 == 1)
				to_double->has_sticky = true;
			strtod_half_array_base(to_double->end, \
				&(to_double->lsb), &(to_double->msb), to_double->base);
			++(to_double->exp);
		}
	}
	else
	{
		while (to_double->exp > 1 && !is_normalized(to_double))
		{
			strtod_double_array_base(to_double->fixed_point, \
				&(to_double->lsb), &(to_double->msb), to_double->base);
			--(to_double->exp);
		}
		if (to_double->tens_digit <= to_double->lsb)
			to_double->exp = 0;
	}
}

static bool	is_normalized(t_to_double *to_double)
{
	return (*(to_double->ones_digit) == 1 \
				&& to_double->lsb == to_double->ones_digit);
}
