/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv_pattern_private.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 22:16:37 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/08 22:28:14 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UV_PATTERN_PRIVATE_H
# define UV_PATTERN_PRIVATE_H

# include <stddef.h>

# include "object.h"

void	set_uv_pattern(size_t id, t_uv_pattern const *pattern);

#endif
