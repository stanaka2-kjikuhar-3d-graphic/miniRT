/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fov.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 23:42:55 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/11 23:51:08 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "ft_math.h"
#include "ft_error.h"
#include "../parse_file_private.h"

bool	parse_fov(char const *element, double *fov)
{
	if (!parse_double(element, fov))
		return (false);
	if (*fov <= 0.0 || 180.0 <= *fov)
	{
		print_error(ERROR_FOV_RANGE);
		return (false);
	}
	*fov *= DEG_TO_RAD;
	return (true);
}
