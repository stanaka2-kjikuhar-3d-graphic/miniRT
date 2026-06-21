/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 00:57:00 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/21 16:12:16 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# ifdef __APPLE__
#  define WINDOW_WIDTH 1280
#  define WINDOW_HEIGHT 780
# else
#  define WINDOW_WIDTH 1920
#  define WINDOW_HEIGHT 1080
# endif

# define WINDOW_TITLE "miniRT"

# define FRAME_RATE 24
# define SEC_TO_USEC 1000000

# define PIXEL_PER_ROTATE 16

# define EPSILON 0.000001 // 1e-6
# define SHADOW_EPSILON 0.000000001 // 1e-8

// # define I_AMBIENT 1.0
// # define I_DIFFUSE 1.0
// # define I_SPECULAR 1.0
# define K_AMBIENT 1.0
# define K_DIFFUSE 0.4
# define K_SPECULAR 0.4
# define SHININESS 32.0

#endif
