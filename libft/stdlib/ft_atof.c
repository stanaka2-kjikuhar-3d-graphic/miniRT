/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 02:41:50 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/01 20:48:29 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "ft_ctype.h"
#include "ft_stdlib.h"

static uint64_t	calc_significand(const char *str);
static int		calc_scaling_exponent(const char *str, uint64_t significand);
static int		get_digits(uint64_t n);

/*
** ft_atof - convert a string to a double
**
** Not fully compatible with atof().
** Does not guarantee correct rounding for decimal strings up to 20 digits
** as required by IEEE 754.
** Round-half-to-even is not implemented; results may differ by 1 ULP.
*/
double	ft_atof(const char *str)
{
	int				sign;
	uint64_t		significand;
	int				exponent;
	double			scaling_factor;
	unsigned int	i;

	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*(str++) == '-')
			sign = -1;
	}
	significand = calc_significand(str);
	if (significand == 0)
		return (sign * 0.0);
	exponent = calc_scaling_exponent(str, significand);
	scaling_factor = 1.0;
	i = 0;
	while (i++ < ft_abs_uint(exponent))
		scaling_factor *= 10;
	if (exponent >= 0)
		return (sign * (double)significand * scaling_factor);
	return (sign * (double)significand / scaling_factor);
}

static uint64_t	calc_significand(const char *str)
{
	uint64_t	significand;
	int			i;

	significand = 0;
	i = 0;
	while (i < 19 && *str != '\0')
	{
		if (*str != '.' && !(i == 0 && *str == '0'))
		{
			significand = significand * 10 + (uint64_t)(*str - '0');
			++i;
		}
		++str;
	}
	return (significand);
}

static int	calc_scaling_exponent(const char *str, uint64_t significand)
{
	int			normalized_exponent;
	const int	digits = get_digits(significand);
	int			scaling_exponent;

	while (*str == '0')
		++str;
	if (*str == '.')
	{
		str += 1;
		normalized_exponent = -1;
		while (*(str++) == '0' && normalized_exponent >= -1074)
			--normalized_exponent;
	}
	else
	{
		str += 1;
		normalized_exponent = 0;
		while (ft_isdigit(*(str++)) && normalized_exponent <= 309)
			++normalized_exponent;
	}
	if (normalized_exponent < 0 || normalized_exponent + 1 >= digits)
		scaling_exponent = normalized_exponent - (digits - 1);
	else
		scaling_exponent = -(digits - (normalized_exponent + 1));
	return (scaling_exponent);
}

static int	get_digits(uint64_t n)
{
	int	digits;

	digits = 1;
	n /= 10;
	while (n != 0)
	{
		++digits;
		n /= 10;
	}
	return (digits);
}

// bool	validate_floating_point_form(const char *str)
// {
// 	if (*str == '-' || *str == '+')
// 		++str;
// 	if (*str == '\0' || (*str == '.' && *(str + 1) == '\0'))
// 		return (false);
// 	while (ft_isdigit(*str))
// 		++str;
// 	if (*str == '.')
// 		++str;
// 	while (ft_isdigit(*str))
// 		++str;
// 	return (*str == '\0');
// }
