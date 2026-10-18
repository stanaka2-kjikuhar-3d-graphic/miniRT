/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_buffer.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 17:36:29 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/18 08:04:48 by stanaka2         ###   ########.fr       */
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
void			*get_window_buffer_ptr(enum e_window_buffer_id id);
unsigned int	get_window_buffer_pixel(\
					enum e_window_buffer_id id, t_ivec2 pixel);
void			put_color(enum e_window_buffer_id id, t_ivec2 pixel, int color);

#endif
