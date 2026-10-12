/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infinite_objects_private.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 19:15:02 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/16 20:12:54 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFINITE_OBJECTS_PRIVATE_H
# define INFINITE_OBJECTS_PRIVATE_H

# include <stdbool.h>
# include <stddef.h>

# include "object.h"

# include "../accelerator_private.h"

bool	allocate_infinite_objects(size_t infinite_count);
void	register_infinite_object(t_object const *object, size_t i);

#endif
