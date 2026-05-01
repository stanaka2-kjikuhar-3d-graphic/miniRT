/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:25:59 by stanaka2          #+#    #+#             */
/*   Updated: 2026/03/13 00:08:08 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "math.h"

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# define DEG_TO_RAD 0.01745329251994329547 // (M_PI / 180.0)
# define RAD_TO_DEG 57.29577951308232286465 // (180.0 / M_PI)

double	degree_to_radian(double degree);

#endif