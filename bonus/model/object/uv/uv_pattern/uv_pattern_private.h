/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv_pattern_private.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 22:16:37 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/17 01:07:54 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UV_PATTERN_PRIVATE_H
# define UV_PATTERN_PRIVATE_H

# include <stddef.h>

# include "object.h"
# include "id.h"

void	set_uv_pattern(t_id object_id, t_uv_pattern const *pattern);

#endif
