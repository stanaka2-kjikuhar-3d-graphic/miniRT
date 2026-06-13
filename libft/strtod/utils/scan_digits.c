/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_digits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 06:03:11 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/13 17:17:55 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "ft_ctype.h"
#include "./ft_strtod_internal.h"

static void	scan_int_digits(\
	const char **nptr, const char *radix_point, t_to_double *to_double);
static void	scan_frac_digits(\
	const char **nptr, const char *radix_point, t_to_double *to_double);

void	scan_digits(const char *nptr, t_to_double *to_double)
{
	const char	*radix_point;

	while (*nptr == '0')
		++nptr;
	radix_point = nptr;
	while (ft_isdigit(*radix_point))
		++radix_point;
	if (INT_DIGITS < radix_point - nptr)
	{
		to_double->is_inf = true;
		return ;
	}
	scan_int_digits(&nptr, radix_point, to_double);
	if (*radix_point == '.')
		++nptr;
	scan_frac_digits(&nptr, radix_point, to_double);
}

static void	scan_int_digits(\
	const char **nptr, const char *radix_point, t_to_double *to_double)
{
	ptrdiff_t	i;

	while (*nptr != radix_point)
	{
		i = radix_point - *nptr - 1;
		to_double->int_tail[-i] = **nptr - '0';
		if (**nptr != '0')
		{
			if (to_double->lsb == NULL)
				to_double->lsb = &(to_double->int_tail[-i]);
			to_double->msb = &(to_double->int_tail[-i]);
		}
		++(*nptr);
	}
}

static void	scan_frac_digits(\
	const char **nptr, const char *radix_point, t_to_double *to_double)
{
	ptrdiff_t	i;

	while (ft_isdigit(**nptr))
	{
		if (*nptr - radix_point <= FRAC_DIGITS)
		{
			i = *nptr - radix_point - 1;
			to_double->frac_head[i] = **nptr - '0';
			if (**nptr != '0')
			{
				if (to_double->lsb == NULL)
					to_double->lsb = &(to_double->frac_head[i]);
				to_double->msb = &(to_double->frac_head[i]);
			}
		}
		else if (**nptr != '0')
			to_double->is_sticky = true;
		++(*nptr);
	}
}
