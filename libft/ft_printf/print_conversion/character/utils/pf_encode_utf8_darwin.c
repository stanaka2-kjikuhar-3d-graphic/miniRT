/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_encode_utf8_darwin.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 00:46:29 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/01 22:52:58 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>

void	pf_encode_utf8(wchar_t wc, unsigned char *utf8)
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
	else if (0x10000 <= wc && wc <= 0x10FFFF)
	{
		utf8[0] = ((unsigned char)((wc >> 18) & 0b00000111)) | 0b11110000;
		utf8[1] = ((unsigned char)((wc >> 12) & 0b00111111)) | 0b10000000;
		utf8[2] = ((unsigned char)((wc >> 6) & 0b00111111)) | 0b10000000;
		utf8[3] = ((unsigned char)(wc & 0b00111111)) | 0b10000000;
	}
}
