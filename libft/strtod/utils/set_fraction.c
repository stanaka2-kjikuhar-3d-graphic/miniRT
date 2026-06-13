/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fraction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 06:03:19 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/13 17:24:37 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#include "./ft_strtod_internal.h"

static bool	is_infinity(t_to_double *to_double);
static void	round_to_nearest_even(t_to_double *to_double);

void	set_fraction(t_to_double *to_double)
{
	size_t	i;

	if (is_infinity(to_double))
	{
		to_double->frac = 0;
		return ;
	}
	*(to_double->int_tail) = 0;
	i = 0;
	while (i++ < DBL_FRACTION)
	{
		double_array(to_double->fixed, &(to_double->lsb), &(to_double->msb));
		to_double->frac <<= 1;
		if (*(to_double->int_tail) % 2 == 1)
			to_double->frac |= 1ULL;
	}
	round_to_nearest_even(to_double);
}

static bool	is_infinity(t_to_double *to_double)
{
	return (to_double->exp == (1UL << DBL_EXPONENT) - 1);
}

static void	round_to_nearest_even(t_to_double *to_double)
{
	ptrdiff_t	i;

	i = 1;
	while (i < FRAC_DIGITS && to_double->frac_head[i] == 0)
		++i;
	if (*(to_double->frac_head) > 5 \
		|| (*(to_double->frac_head) == 5 \
			&& (*(to_double->int_tail) % 2 == 1
				|| to_double->is_sticky || i < FRAC_DIGITS)))
	{
		++(to_double->frac);
	}
	if (to_double->frac & (1ULL << DBL_FRACTION))
	{
		to_double->frac = 0;
		++(to_double->exp);
	}
}
