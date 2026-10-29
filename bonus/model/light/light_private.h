/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_private.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 19:31:12 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/18 09:31:33 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_PRIVATE_H
# define LIGHT_PRIVATE_H

# include <stdbool.h>
# include <stddef.h>

# include "light.h"
# include "dynamic_array.h"

bool			add_light_id(size_t index, t_light_id *id);
size_t			get_light_index(t_light_id id);
void			cleanup_light_ids(void);
t_dynamic_array	*get_mutable_light_array(void);
t_light			*get_mutable_light(t_light_id id);

#endif
