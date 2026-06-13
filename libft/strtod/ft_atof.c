/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 00:33:25 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/13 17:39:05 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"
#include "ft_string.h"
#include "./ft_strtod_internal.h"

double	ft_atof(const char *nptr)
{
	t_to_double	to_double;

	ft_bzero(&to_double, sizeof(t_to_double));
	to_double.int_tail = &(to_double.fixed[INT_DIGITS - 1]);
	to_double.frac_head = &(to_double.fixed[INT_DIGITS]);
	to_double.end = &(to_double.fixed[BUF_SIZE - 1]);
	while (ft_isspace(*nptr))
		++nptr;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			to_double.sign = 1ULL;
		++nptr;
	}
	scan_digits(nptr, &to_double);
	if (to_double.is_inf)
	{
		to_double.exp = (1ULL << DBL_EXPONENT) - 1;
		return (encode_double(&to_double));
	}
	set_exponent(&to_double);
	set_fraction(&to_double);
	return (encode_double(&to_double));
}
