/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_literal_inf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 21:41:44 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/13 21:42:42 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "ft_ctype.h"
#include "ft_stdlib.h"
#include "../ft_strtod_internal.h"

bool	scan_literal_nan(const char **nptr, t_to_double *to_double)
{
	ptrdiff_t	i;

	if (((*nptr)[0] == 'i' || (*nptr)[0] == 'I') \
		&& ((*nptr)[1] == 'n' || (*nptr)[1] == 'N') \
		&& ((*nptr)[2] == 'f' || (*nptr)[2] == 'F'))
	{
		*nptr += 3;
		to_double->exp = 255;
		to_double->frac = 0;
		return (true);
	}
	return (false);
}