/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 00:44:43 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/13 17:37:08 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRTOD_INTERNAL_H
# define FT_STRTOD_INTERNAL_H

/*
#include <unicode/utypes.h> is workaround for #include <float.h>
due to norminette=3.3.55 bug.
*/
# include <unicode/utypes.h>

# include <stddef.h>
# include <stdint.h>
# include <stdbool.h>

// INT_DIGITS: BINARY64_MAX = 1.80×10^308
# define INT_DIGITS 309
// FRAC_DIGITS: 52 + |-1022| + 1(0.5ULP) = 1075
# define FRAC_DIGITS 1075
// BUF_SIZE: INT_DIGITS(309) + FRAC_DIGITS(1075) = 1384
# define BUF_SIZE 1384

# define DBL_EXPONENT 11
# define DBL_FRACTION 52
# define DBL_EMAX 1023

# define DBL_SIGN_SHIFT 63
# define DBL_EXPONENT_SHIFT 52

union u_double
{
	double		value;
	uint64_t	raw_bits;
};

/*
** t_to_double: working context for one decimal -> double conversion.
** ft_atof MUST set int_tail, frac_head and end before any phase runs.
** Each phase mutates this struct in place.
**
** fixed[]: the magnitude as a base-10 fixed-point number.
**   fixed[0 .. INT_DIGITS-1]        integer part
**   fixed[INT_DIGITS .. BUF_SIZE-1] fraction
** The radix point is placed between fixed[INT_DIGITS-1] and fixed[INT_DIGITS].
**
** int_tail : &fixed[INT_DIGITS-1], units digit; int_tail[-k] = higher.
** frac_head: &fixed[INT_DIGITS], first fraction digit; frac_head[k] = lower.
** end      : &fixed[BUF_SIZE-1], least significant fraction slot.
** lsb, msb : bound the active window of nonzero digits (lowest/highest
**            array index). Both NULL when the value is zero. half_array
**            and double_array work only on [lsb, msb] and keep them in
**            sync: extend on carry-out, trim leading/trailing zeros.
**
** sign     : IEEE sign bit (0 or 1).
** exp      : IEEE biased exponent field (filled by set_exponent).
** frac     : IEEE 52-bit mantissa field (filled by set_fraction).
** is_inf   : set by scan_digits on integer overflow; forces infinity.
** is_sticky: nonzero digits dropped past tracked precision; feeds
**            round-half-to-even.
*/
typedef struct s_to_double
{
	uint8_t			fixed[BUF_SIZE];
	uint8_t			*int_tail;
	uint8_t			*frac_head;
	uint8_t			*end;
	uint8_t			*lsb;
	uint8_t			*msb;
	uint64_t		sign;
	uint64_t		exp;
	uint64_t		frac;
	bool			is_inf;
	bool			is_sticky;
}	t_to_double;

void	scan_digits(const char *nptr, t_to_double *to_double);
void	set_exponent(t_to_double *to_double);
void	set_fraction(t_to_double *to_double);
void	half_array(uint8_t *array_end, uint8_t **lsb, uint8_t **msb);
void	double_array(uint8_t *array_start, uint8_t **lsb, uint8_t **msb);
double	encode_double(t_to_double *to_double);

#endif
