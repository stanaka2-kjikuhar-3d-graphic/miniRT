/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_dynamic_array.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 23:25:40 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/15 23:40:41 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "dynamic_array.h"

void	cleanup_dynamic_array(t_dynamic_array *dynamic_array)
{
	if (dynamic_array->data == NULL)
		return ;
	free(dynamic_array->data);
	dynamic_array->data = NULL;
	dynamic_array->capacity = 0;
	dynamic_array->used = 0;
}
