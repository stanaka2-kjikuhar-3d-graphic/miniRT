/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 21:08:44 by stanaka2          #+#    #+#             */
/*   Updated: 2026/07/16 15:06:47 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#include "mlx.h"
#include "ft_stdio.h"
#include "ft_string.h"

#include "config.h"
#include "color.h"
#include "parser.h"
#include "light.h"
#include "object.h"
#include "ft_mlx.h"
#include "renderer.h"

static bool	is_valid_argument(int argc, char const *argv[]);
static void	cleanup(void);

int	main(int argc, char const *argv[])
{
	init_color_lut();
	if (!is_valid_argument(argc, argv))
	{
		ft_dprintf(STDERR_FILENO, "Error\n");
		ft_dprintf(STDERR_FILENO, "Usage: %s *.rt\n", argv[0]);
		return (EXIT_FAILURE);
	}
	if (!create_mlx_connection())
		return (EXIT_FAILURE);
	if (!parser(argv[1]) || !setup_mlx_window())
	{
		cleanup();
		return (EXIT_FAILURE);
	}
	setup_mlx_hooks();
	mlx_loop(get_mlx_ptr());
	cleanup();
	return (EXIT_SUCCESS);
}

static bool	is_valid_argument(int argc, char const *argv[])
{
	char	*filename;
	size_t	len;

	if (argc != 2)
		return (false);
	filename = ft_strrchr(argv[1], '/');
	if (filename != NULL)
		++filename;
	else
		filename = (char *)argv[1];
	len = ft_strlen(filename);
	if (len <= 3 || ft_strcmp(filename + len - 3, ".rt") != 0)
		return (false);
	return (true);
}

static void	cleanup(void)
{
	cleanup_objects();
	cleanup_lights();
	cleanup_mlx();
}
