/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accelerator_private.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 17:16:15 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/16 20:02:53 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACCELERATOR_PRIVATE_H
# define ACCELERATOR_PRIVATE_H

# include <stdbool.h>

# include "accelerator.h"

bool	build_bvh(void);
void	cleanup_bvh(void);
void	cleanup_aabb_leaves(void);
bool	build_infinite_linear(void);
void	cleanup_infinite_linear(void);

#endif
