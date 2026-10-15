/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_private.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 17:01:07 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/04 22:43:41 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_PRIVATE_H
# define IMAGE_PRIVATE_H

# include "image.h"

typedef struct s_texture_dict
{
	t_image	*texture;
	char	*filepath;
}	t_texture_dict;

#endif
