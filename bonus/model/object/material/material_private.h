/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_private.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 20:40:06 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/25 21:52:54 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_PRIVATE_H
# define MATERIAL_PRIVATE_H

# include <stddef.h>
# include <stdbool.h>

# include "material.h"

bool		add_material_id(size_t index, t_material_id *id);
size_t		get_material_index(t_material_id id);
t_material	*get_mutable_material(t_material_id id);
bool		create_material(t_material_id *id);

#endif