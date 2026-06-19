/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 01:09:47 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/19 03:11:20 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef struct s_color
{
	double	r;
	double	g;
	double	b;
}	t_color;

enum e_color_channel
{
	RED,
	GREEN,
	BLUE
};

int		calc_rgb(t_color color);
t_color	add_color(t_color a, t_color b);
t_color	mul_color(t_color a, t_color b);
t_color	scale_color(double t, t_color color);

#endif
