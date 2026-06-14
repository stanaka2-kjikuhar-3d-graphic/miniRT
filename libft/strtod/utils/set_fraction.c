/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fraction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 06:03:19 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/14 19:28:01 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdbool.h>

#include "../ft_strtod_internal.h"

static void	round_to_nearest_even(t_to_double *to_double);

void	set_fraction(t_to_double *to_double)
{
	size_t	i;

	*(to_double->ones_digit) = 0;
	i = 0;
	while (i++ < DBL_FRACTION)
	{
		double_array_base(to_double->fixed_point, \
			&(to_double->lsb), &(to_double->msb), to_double->base);
		to_double->frac <<= 1;
		if (*(to_double->ones_digit) % 2 == 1)
			to_double->frac |= 1ULL;
	}
	round_to_nearest_even(to_double);
}

static void	round_to_nearest_even(t_to_double *to_double)
{
	uint8_t		half;

	half = to_double->base / 2;
	if (*(to_double->tens_digit) > half \
		|| (*(to_double->tens_digit) == half \
			&& (*(to_double->ones_digit) % 2 == 1
				|| to_double->has_sticky \
				|| to_double->tens_digit < to_double->msb)))
	{
		++(to_double->frac);
	}
	if (to_double->frac & (1ULL << DBL_FRACTION))
	{
		to_double->frac = 0;
		++(to_double->exp);
	}
}
