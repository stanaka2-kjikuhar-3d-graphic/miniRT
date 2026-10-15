/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_private.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 07:42:48 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/06 22:38:07 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_PRIVATE_H
# define OBJECT_PRIVATE_H

# include <stddef.h>

bool		add_object_id(size_t index, size_t *id);
size_t		get_object_id(size_t id);
void		cleanup_object_ids(void);
t_object	*get_mutable_object(size_t id);

#endif
