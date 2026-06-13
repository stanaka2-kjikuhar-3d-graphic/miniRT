/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:46:30 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/13 16:08:21 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>

static void	update_lsb_and_msb(uint8_t **lsb, uint8_t **msb);

void	half_array(uint8_t *array_end, uint8_t **lsb, uint8_t **msb)
{
	uint8_t	*left;
	uint8_t	*right;
	uint8_t	carry;

	left = *lsb;
	right = *msb;
	if (left == NULL || right == NULL)
		return ;
	carry = 0;
	while (left <= right)
	{
		*left += carry;
		carry = (*left % 2) * 10;
		*left = *left / 2;
		++left;
	}
	if (carry != 0 && left <= array_end)
	{
		*left = carry / 2;
		*msb = left;
	}
	update_lsb_and_msb(lsb, msb);
}

void	double_array(uint8_t *array_start, uint8_t **lsb, uint8_t **msb)
{
	uint8_t	*left;
	uint8_t	*right;
	uint8_t	carry;

	left = *lsb;
	right = *msb;
	if (left == NULL || right == NULL)
		return ;
	carry = 0;
	while (left <= right)
	{
		*right = *right * 2 + carry;
		carry = *right / 10;
		*right %= 10;
		--right;
	}
	if (carry != 0 && array_start <= right)
	{
		*right = carry;
		*lsb = right;
	}
	update_lsb_and_msb(lsb, msb);
}

static void	update_lsb_and_msb(uint8_t **lsb, uint8_t **msb)
{
	if (*lsb == NULL || *msb == NULL)
		return ;
	while (*lsb <= *msb)
	{
		if (**lsb != 0)
			break ;
		++(*lsb);
	}
	if (*lsb > *msb)
	{
		*lsb = NULL;
		*msb = NULL;
		return ;
	}
	while (*lsb <= *msb)
	{
		if (**msb != 0)
			break ;
		--(*msb);
	}
}
