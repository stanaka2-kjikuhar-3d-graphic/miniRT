/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_private.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 19:31:12 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/11 19:35:16 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_PRIVATE_H
# define LIGHT_PRIVATE_H

# include <stdbool.h>
# include <stddef.h>

# include "light.h"

bool	add_light_id(size_t index, size_t *id);
size_t	get_light_id(size_t id);
void	cleanup_light_ids(void);
t_light	*get_mutable_light(size_t id);

#endif
