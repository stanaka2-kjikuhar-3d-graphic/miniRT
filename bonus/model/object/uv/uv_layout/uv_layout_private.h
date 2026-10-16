/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv_layout_private.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 21:02:01 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/17 01:07:54 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UV_LAYOUT_PRIVATE_H
# define UV_LAYOUT_PRIVATE_H

# include <stddef.h>

# include "object.h"
# include "range.h"
# include "id.h"

void	set_uv_layout(t_id object_id, t_uv_layout const *layout);

#endif
