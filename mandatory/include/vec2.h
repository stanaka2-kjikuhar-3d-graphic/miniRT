/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 17:37:50 by stanaka2          #+#    #+#             */
/*   Updated: 2026/04/06 16:03:53 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC2_H
# define VEC2_H

# include "type.h"

struct s_dvec2
{
	double	x;
	double	y;
};

struct s_ivec2
{
	int	x;
	int	y;
};

t_dvec2	dvec2(double x, double y);
t_dvec2	dvec2_normalize(t_dvec2 v);
double	dvec2_length(t_dvec2 v);
t_dvec2	dvec2_scale(t_dvec2 v, double s);
t_dvec2	dvec2_rotate(t_dvec2 v, double radian);
t_dvec2	dvec2_add(t_dvec2 a, t_dvec2 b);
t_dvec2	dvec2_sub(t_dvec2 a, t_dvec2 b);
double	dvec2_dot(t_dvec2 a, t_dvec2 b);
double	dvec2_cross(t_dvec2 a, t_dvec2 b);

t_ivec2	ivec2(int x, int y);
double	ivec2_length(t_ivec2 v);
t_ivec2	ivec2_scale(t_ivec2 v, int s);
t_ivec2	ivec2_add(t_ivec2 a, t_ivec2 b);
t_ivec2	ivec2_sub(t_ivec2 a, t_ivec2 b);
int		ivec2_dot(t_ivec2 a, t_ivec2 b);
int		ivec2_cross(t_ivec2 a, t_ivec2 b);

#endif
