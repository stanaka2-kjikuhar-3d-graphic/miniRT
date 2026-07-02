/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_option_id.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 02:33:05 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/03 02:39:10 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>

#include "ft_string.h"

bool	is_option_id(char const *id, char const *option_element)
{
	size_t	len;

	len = ft_strlen(id);
	return (ft_strncmp(id, option_element, len) == 0 \
				&& option_element[len] == '=');
}
