/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_scan_exponent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 22:31:30 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/13 22:48:53 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "ft_ctype.h"
#include "ft_stdlib.h"
#include "../ft_strtod_internal.h"

long	pre_scan_exponent(const char *nptr, t_to_double *to_double)
{
	while (ft_isdigit(*nptr))
		++nptr;
	if (*nptr == '.')
		++nptr;
	while (ft_isdigit(*nptr))
		++nptr;
	if (to_double->base == 10 && (**nptr == 'e' || **nptr == 'E'))
		return (ft_strtol(*nptr, NULL, 10));
	else if (to_double->base == 16 && (**nptr == 'p' || **nptr == 'P'))
		return (ft_strtol(*nptr, NULL, 10));
	else
		return (0);
}
