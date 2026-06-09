/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_encode_utf8.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 17:16:04 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/01 22:53:15 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>

static void	pf_encode_utf8_0x0_0xffff(unsigned char *utf8, wchar_t wc);
static void	pf_encode_utf8_0x10000_0x7fffffff(unsigned char *utf8, wchar_t wc);

void	pf_encode_utf8(wchar_t wc, unsigned char *utf8)
{
	if (0x0 <= wc && wc <= 0xFFFF)
		pf_encode_utf8_0x0_0xffff(utf8, wc);
	else if (0x10000 <= wc && wc <= 0x7FFFFFFF)
		pf_encode_utf8_0x10000_0x7fffffff(utf8, wc);
}

static void	pf_encode_utf8_0x0_0xffff(unsigned char *utf8, wchar_t wc)
{
	if (0x0000 <= wc && wc <= 0x007F)
	{
		utf8[0] = ((unsigned char)(wc & 0b01111111)) | 0b00000000;
	}
	else if (0x0080 <= wc && wc <= 0x07FF)
	{
		utf8[0] = ((unsigned char)((wc >> 6) & 0b00011111)) | 0b11000000;
		utf8[1] = ((unsigned char)(wc & 0b00111111)) | 0b10000000;
	}
	else if (0x0800 <= wc && wc <= 0xFFFF)
	{
		utf8[0] = ((unsigned char)((wc >> 12) & 0b00001111)) | 0b11100000;
		utf8[1] = ((unsigned char)((wc >> 6) & 0b00111111)) | 0b10000000;
		utf8[2] = ((unsigned char)(wc & 0b00111111)) | 0b10000000;
	}
}

static void	pf_encode_utf8_0x10000_0x7fffffff(unsigned char *utf8, wchar_t wc)
{
	if (0x10000 <= wc && wc <= 0x1FFFFF)
	{
		utf8[0] = ((unsigned char)((wc >> 18) & 0b00000111)) | 0b11110000;
		utf8[1] = ((unsigned char)((wc >> 12) & 0b00111111)) | 0b10000000;
		utf8[2] = ((unsigned char)((wc >> 6) & 0b00111111)) | 0b10000000;
		utf8[3] = ((unsigned char)(wc & 0b00111111)) | 0b10000000;
	}
	else if (0x200000 <= wc && wc <= 0x3FFFFFF)
	{
		utf8[0] = ((unsigned char)((wc >> 24) & 0b00000011)) | 0b11111000;
		utf8[1] = ((unsigned char)((wc >> 18) & 0b00111111)) | 0b10000000;
		utf8[2] = ((unsigned char)((wc >> 12) & 0b00111111)) | 0b10000000;
		utf8[3] = ((unsigned char)((wc >> 6) & 0b00111111)) | 0b10000000;
		utf8[4] = ((unsigned char)(wc & 0b00111111)) | 0b10000000;
	}
	else if (0x4000000 <= wc && wc <= 0x7FFFFFFF)
	{
		utf8[0] = ((unsigned char)((wc >> 30) & 0b00000001)) | 0b11111100;
		utf8[1] = ((unsigned char)((wc >> 24) & 0b00111111)) | 0b10000000;
		utf8[2] = ((unsigned char)((wc >> 18) & 0b00111111)) | 0b10000000;
		utf8[3] = ((unsigned char)((wc >> 12) & 0b00111111)) | 0b10000000;
		utf8[4] = ((unsigned char)((wc >> 6) & 0b00111111)) | 0b10000000;
		utf8[5] = ((unsigned char)(wc & 0b00111111)) | 0b10000000;
	}
}
