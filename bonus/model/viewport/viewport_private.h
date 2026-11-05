/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport_private.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 14:15:38 by stanaka2          #+#    #+#             */
/*   Updated: 2026/11/02 06:50:17 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEWPORT_PRIVATE_H
# define VIEWPORT_PRIVATE_H

# include <stdbool.h>

# include "viewport.h"

t_viewport	*get_mutable_viewport(void);
bool		init_resolution(t_resolution *resolution);

#endif
