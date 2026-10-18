/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_buffer_private.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 08:09:08 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/18 08:41:52 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_BUFFER_PRIVATE_H
# define WINDOW_BUFFER_PRIVATE_H

# include "window_buffer.h"

# include "../image_private.h"

t_image	*get_window_buffer(enum e_window_buffer_id id);

#endif
