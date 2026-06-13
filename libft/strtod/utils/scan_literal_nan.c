/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_literal_nan.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 21:08:04 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/13 21:41:06 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "ft_ctype.h"
#include "ft_stdlib.h"
#include "../ft_strtod_internal.h"

bool	scan_literal_nan(const char **nptr, t_to_double *to_double)
{
	ptrdiff_t	i;

	if (((*nptr)[0] == 'n' || (*nptr)[0] == 'N') \
		&& ((*nptr)[1] == 'a' || (*nptr)[1] == 'A') \
		&& ((*nptr)[2] == 'n' || (*nptr)[2] == 'N'))
	{
		*nptr += 3;
		to_double->exp = 0;
		i = 0;
		if ((*nptr)[i++] == '(')
		{
			while (ft_isalnum((*nptr)[i]))
				++i;
			if (*nptr[i] == ')')
			{
				ft_strtol(++(*nptr), NULL, 0);
				++(*nptr);
			}
		}
		return (true);
	}
	return (false);
}
