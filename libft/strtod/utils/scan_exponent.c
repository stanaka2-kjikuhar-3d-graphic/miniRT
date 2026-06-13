/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_exponent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 19:25:41 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/13 22:39:32 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "ft_stdlib.h"
#include "../ft_strtod_internal.h"

void	scan_exponent(const char **nptr, t_to_double *to_double)
{
	if (to_double->base == 10 && (**nptr == 'e' || **nptr == 'E'))
		ft_strtol(*nptr, NULL, 10);
	else if (to_double->base == 16 && (**nptr == 'p' || **nptr == 'P'))
		ft_strtol(*nptr, NULL, 10);
}
