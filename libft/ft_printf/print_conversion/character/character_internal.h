/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 21:44:12 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/04 01:25:26 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_INTERNAL_H
# define CHARACTER_INTERNAL_H

# include <stdbool.h>
# include <stddef.h>
# include <wchar.h>

# include "ft_printf/types.h"

# ifdef __APPLE__
// REC2279
#  define UTF8_SIZE 6
# else
// REC3629
#  define UTF8_SIZE 4
# endif

void	pf_print_null(t_ctx *ctx, t_conv *conv);
bool	pf_validate_codepoint(wchar_t wc);
size_t	pf_calc_utf8_len(wchar_t wc);
void	pf_encode_utf8(wchar_t wc, unsigned char *utf8);

#endif
