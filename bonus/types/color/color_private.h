/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_private.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 23:12:24 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/29 00:48:06 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_PRIVATE_H
# define COLOR_PRIVATE_H

# include <stdint.h>

void	init_srgb_lut(void);
float	decode_srgb(uint8_t srgb);
uint8_t	encode_srgb(float linear);
void	init_gamma_lut(void);
float	decode_gamma(uint8_t gamma_encoded);
uint8_t	encode_gamma(float linear);

#endif
