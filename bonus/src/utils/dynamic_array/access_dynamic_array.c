/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_dynamic_array.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/16 00:18:26 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/16 00:19:18 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dynamic_array.h"

void	*access_dynamic_array(t_dynamic_array const *dynamic_array, size_t i)
{
	return ((char *)(dynamic_array->data) + (i * dynamic_array->type_size));
}
