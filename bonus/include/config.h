/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 00:57:00 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/03 23:53:22 by stanaka2         ###   ########.fr       */
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

# define EPSILON 0.000001f // 1e-6

# define ENCODING_SRGB 0
# define ENCODING_GAMMA 1
# define COLOR_ENCODING_MODE ENCODING_SRGB
# define GAMMA 2.2

# define PHONG_MODEL 0
# define BLINN_PHONG_MODEL 1
# define RENDERING_MODEL PHONG_MODEL

# define FRAME_RATE 24
# define SEC_TO_USEC 1000000

# define PIXEL_PER_ROTATE 16

# define SPOT_LIGHT_FALLOFF 1.0
# define LIGHT_RANGE 3250.0f

# define DEFAULT_SHININESS 32.0f
# define DEFAULT_PATTERN_SIZE 10.0f
# define DEFAULT_BUMP_STRENGTH 1.0f
# define DEFAULT_CHECKER_COUNT 4

#endif
