/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_private.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 17:01:07 by stanaka2          #+#    #+#             */
/*   Updated: 2026/11/01 17:03:00 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_PRIVATE_H
# define TEXTURE_PRIVATE_H

# include <stdbool.h>
# include <stddef.h>

# include "texture.h"
# include "dynamic_array.h"

# include "../image_private.h"

typedef struct s_texture
{
	t_texture_id	id;
	t_image			*image;
	char			*filepath;
}	t_texture;

t_image	*get_texture(t_texture_id id);
bool	create_texture_image(char *filepath, t_texture *texture);
bool	add_texture_id(size_t index, t_texture_id *id);
size_t	get_texture_index(t_texture_id id);
void	cleanup_texture_ids(void);

#endif
