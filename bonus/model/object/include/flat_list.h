/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flat_list.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 17:56:38 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/15 06:52:20 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAT_LIST_H
# define FLAT_LIST_H

#include <stdbool.h>
#include <stddef.h>

#include "object.h"

bool			allocate_flat_list(size_t count);
void			register_flat_list(size_t i, size_t object_id);
bool			add_flat_list(size_t object_id);
t_object const	*get_flat_list_node(size_t i);
size_t			get_flat_list_count(void);
void			set_flat_list_count(size_t count);
void			clear_flat_list_count(void);

#endif
