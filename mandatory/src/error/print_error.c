/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 12:53:18 by stanaka2          #+#    #+#             */
/*   Updated: 2026/03/11 13:01:45 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_error(char *error_msg)
{
	ft_dprintf(STDERR_FILENO, "Error\n");
	ft_dprintf(STDERR_FILENO, "%s\n", error_msg);
}
