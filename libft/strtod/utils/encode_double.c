/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encode_double.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 06:09:36 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/13 06:15:31 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "./ft_strtod_internal.h"

double	encode_double(t_to_double *to_double)
{
	union u_double	num;

	num.raw_bits = (to_double->sign << DBL_SIGN_SHIFT) \
					| (to_double->exp << DBL_EXPONENT_SHIFT) \
					| to_double->frac;
	return (num.value);
}
