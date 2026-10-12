/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builder_private.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 02:26:53 by stanaka2          #+#    #+#             */
/*   Updated: 2026/09/17 02:27:37 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILDER_PRIVATE_H
# define BUILDER_PRIVATE_H

# include <stdbool.h>

# include "vector.h"

bool	rebase_world_space(t_vec3 rebased_origin);

#endif
