/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_array.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 23:07:15 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/16 01:45:47 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DYNAMIC_ARRAY_H
# define DYNAMIC_ARRAY_H

# include <stddef.h>
# include <stdbool.h>

typedef struct s_dynamic_array
{
	void			*data;
	size_t			capacity;
	size_t			used;
	size_t const	type_size;
}	t_dynamic_array;

bool	allocate_dynamic_array(t_dynamic_array *dynamic_array, size_t new_size);
bool	add_dynamic_array(t_dynamic_array *dynamic_array, void const *data);
bool	grow_dynamic_array(t_dynamic_array *dynamic_array);
void	*access_dynamic_array(t_dynamic_array const *dynamic_array, size_t i);
void	cleanup_dynamic_array(t_dynamic_array *dynamic_array);

#endif
