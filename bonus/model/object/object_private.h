/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_private.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 07:42:48 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/15 07:33:46 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_PRIVATE_H
# define OBJECT_PRIVATE_H

# include <stddef.h>
# include <stdbool.h>

# include "object.h"
# include "dynamic_array.h"

t_dynamic_array	*get_mutable_object_array(void);
t_object		*get_mutable_object(size_t id);
bool			add_object_id(size_t index, size_t *id);
size_t			get_object_index(size_t id);
void			cleanup_objects(void);
void			cleanup_object_ids(void);
void			cleanup_bvh_nodes(void);
void			cleanup_bvh_leaves(void);
void			cleanup_flat_list(void);

#endif
