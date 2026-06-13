/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_exponent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 06:03:15 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/13 17:23:11 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

#include "./ft_strtod_internal.h"

static bool	is_infinity(t_to_double *to_double);
static bool	is_normalized(t_to_double *to_double);

void	set_exponent(t_to_double *to_double)
{
	to_double->exp = DBL_EMAX;
	if (to_double->lsb == NULL)
		to_double->exp = 0;
	else if (to_double->lsb <= to_double->int_tail)
	{
		while (!is_infinity(to_double) && !is_normalized(to_double))
		{
			if (*(to_double->end) % 2 == 1)
				to_double->is_sticky = true;
			half_array(to_double->end, &(to_double->lsb), &(to_double->msb));
			++(to_double->exp);
		}
	}
	else
	{
		while (to_double->exp > 1 && !is_normalized(to_double))
		{
			double_array(to_double->fixed, \
							&(to_double->lsb), &(to_double->msb));
			--(to_double->exp);
		}
		if (*(to_double->int_tail) == 0)
			to_double->exp = 0;
	}
}

static bool	is_infinity(t_to_double *to_double)
{
	return (to_double->exp == (1UL << DBL_EXPONENT) - 1);
}

static bool	is_normalized(t_to_double *to_double)
{
	ptrdiff_t	i;

	if (*(to_double->int_tail) != 1)
		return (false);
	i = 1;
	while (i < INT_DIGITS)
	{
		if (to_double->int_tail[-i] != 0)
			return (false);
		++i;
	}
	return (true);
}
