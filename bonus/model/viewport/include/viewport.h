/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 00:24:54 by stanaka2          #+#    #+#             */
/*   Updated: 2026/11/07 18:22:44 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEWPORT_H
# define VIEWPORT_H

# include <stdint.h>
# include <stdbool.h>

# include "vector.h"
# include "color.h"

enum e_resolution_level
{
	// SIXTEENTH_RESOLUTION,
	// EIGHTH_RESOLUTION,
	QUARTER_RESOLUTION,
	HALF_RESOLUTION,
	FULL_RESOLUTION,
	RESOLUTION_COUNT,
	RESOLUTION_OFF
};

enum e_interpolation_type
{
	NEAREST_INTERPOLATION,
	BILINEAR_INTERPOLATION
};

typedef struct s_resolution
{
	enum e_resolution_level		level;
	enum e_interpolation_type	interpolation;
	uint8_t						scale[RESOLUTION_COUNT];
	t_ivec2						*render_pixel[RESOLUTION_COUNT];
	size_t						render_pixel_count[RESOLUTION_COUNT];
}	t_resolution;

typedef struct s_viewport
{
	t_color					*buffer;
	size_t					sample_count;
	t_resolution			resolution;
	float					aspect_ratio;
	t_vec2					half_size;
}	t_viewport;

enum e_buffering_mode
{
	BUFFERING_OVERWRITE,
	BUFFERING_ACCUMULATE
};

t_viewport const	*get_viewport(void);
bool				init_viewport(float fov);
void				refresh_viewport(void);
void				change_viewport_fov(float fov);
void				set_resolution_level(enum e_resolution_level level);
void				increment_resolution_level(void);
void				cleanup_viewport(void);
t_color				resolve_viewport_color(t_vec2 uv);
void				put_color_viewport(enum e_buffering_mode mode, \
						t_ivec2 pixel, t_color color);
void				set_sample_count(enum e_buffering_mode mode);
void				switch_viewport_interpolation(void);

#endif
