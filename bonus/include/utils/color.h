/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 01:09:47 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/29 00:32:20 by stanaka2         ###   ########.fr       */
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

t_color	add_color(t_color a, t_color b);
t_color	mul_color(t_color a, t_color b);
t_color	scale_color(float t, t_color color);
int		encode_color(t_color color);
t_color	decode_color(unsigned int rgb);
void	init_color_lut(void);
t_color	convert_uint_to_color(unsigned int rgb);
float	average_rgb(unsigned int rgb);

#endif
