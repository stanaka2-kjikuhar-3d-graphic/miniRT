/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_obj_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 22:17:13 by stanaka2          #+#    #+#             */
/*   Updated: 2026/10/30 08:04:59 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_lst.h"

#include "loader.h"
#include "loader_obj.h"

void	delete_obj_input(void *input)
{
	t_obj_input	obj;

	if (input == NULL)
		return ;
	obj = ((t_input *)input)->obj;
	ft_lstclear(&(obj.v_list), free);
	ft_lstclear(&(obj.vn_list), free);
	ft_lstclear(&(obj.vt_list), free);
	ft_lstclear(&(obj.f_list), free);
	free(input);
}
