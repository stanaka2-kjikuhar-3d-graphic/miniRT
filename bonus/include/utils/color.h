/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 01:09:47 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/15 00:14:16 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include <stdint.h>
# include <stdbool.h>

typedef struct s_color
{
	float	r;
	float	g;
	float	b;
}	t_color;

enum e_color_channel
{
	RED,
	GREEN,
	BLUE
};

int		convert_color_to_int(t_color color);
t_color	convert_uint_to_color(unsigned int rgb);
t_color	add_color(t_color a, t_color b);
t_color	mul_color(t_color a, t_color b);
t_color	scale_color(float t, t_color color);
void	init_srgb_decode_lut(void);
float	decode_srgb(uint8_t srgb);
bool	init_srgb_encoded_lut(void);
uint8_t	encode_srgb(float linear);
void	cleanup_srgb_encoded_lut(void);

#endif
