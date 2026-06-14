/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtod_scan_literal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 16:35:16 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/14 20:03:06 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdbool.h>

#include "ft_ctype.h"
#include "ft_stdlib.h"
#include "../ft_strtod_internal.h"

bool	strtod_scan_literal_nan(const char **nptr, t_to_double *to_double)
{
	size_t	i;

	if (((*nptr)[0] == 'n' || (*nptr)[0] == 'N') \
		&& ((*nptr)[1] == 'a' || (*nptr)[1] == 'A') \
		&& ((*nptr)[2] == 'n' || (*nptr)[2] == 'N'))
	{
		*nptr += 3;
		strtod_set_sign(to_double);
		to_double->exp = 2047;
		to_double->frac = (1ULL << 51);
		i = 0;
		if ((*nptr)[i++] == '(')
		{
			while (ft_isalnum((*nptr)[i]))
				++i;
			if ((*nptr)[i] == ')')
			{
				to_double->frac \
					|= ft_strtol(*nptr + 1, NULL, 0) & ((1ULL << 51) - 1);
				*nptr = &((*nptr)[i + 1]);
			}
		}
		return (true);
	}
	return (false);
}

bool	strtod_scan_literal_inf(const char **nptr, t_to_double *to_double)
{
	if (((*nptr)[0] == 'i' || (*nptr)[0] == 'I') \
		&& ((*nptr)[1] == 'n' || (*nptr)[1] == 'N') \
		&& ((*nptr)[2] == 'f' || (*nptr)[2] == 'F'))
	{
		*nptr += 3;
		to_double->is_inf = true;
		if (((*nptr)[0] == 'i' || (*nptr)[0] == 'I') \
			&& ((*nptr)[1] == 'n' || (*nptr)[1] == 'N') \
			&& ((*nptr)[2] == 'i' || (*nptr)[2] == 'I') \
			&& ((*nptr)[3] == 't' || (*nptr)[3] == 'T') \
			&& ((*nptr)[4] == 'y' || (*nptr)[4] == 'Y'))
		{
			*nptr += 5;
		}
		return (true);
	}
	return (false);
}
