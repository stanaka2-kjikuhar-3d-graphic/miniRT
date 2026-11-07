/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_buffer.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 17:36:29 by stanaka2          #+#    #+#             */
/*   Updated: 2026/11/01 23:03:46 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_BUFFER_H
# define WINDOW_BUFFER_H

# include <stdbool.h>

# include "vector.h"

enum e_window_buffer_id
{
	MAIN_WINDOW_BUFFER,
	WINDOW_BUFFER_COUNT,
};

bool			create_window_buffer(\
					enum e_window_buffer_id id, int width, int height);
void			resolve_viewport_to_window_buffer(enum e_window_buffer_id id);
void			*get_window_buffer_ptr(enum e_window_buffer_id id);
void			put_color_window_buffer(\
					enum e_window_buffer_id id, t_ivec2 pixel, int color);
unsigned int	get_window_buffer_pixel(\
					enum e_window_buffer_id id, t_ivec2 pixel);

#endif
