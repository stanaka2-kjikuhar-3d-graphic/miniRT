/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 21:08:44 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/16 23:48:28 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#include "mlx.h"
#include "ft_stdio.h"
#include "ft_string.h"
#include "parse_file.h"
#include "scene.h"
#include "object.h"
#include "ft_mlx.h"

static bool	is_valid_argument(int argc, char const *argv[]);
static bool	set_mlx(void);

int	main(int argc, char const *argv[])
{
	if (!is_valid_argument(argc, argv))
	{
		ft_dprintf(STDERR_FILENO, "Error\n");
		ft_dprintf(STDERR_FILENO, "Usage: %s *.rt\n", argv[0]);
		return (EXIT_FAILURE);
	}
	if (!parse_file(argv[1]))
		return (EXIT_FAILURE);
	if (!set_mlx())
		return (EXIT_FAILURE);
	cleanup_objects();
	ft_mlx_destroy();
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

static bool	set_mlx(void)
{
	if (!create_mlx_connection())
	{
		cleanup_objects();
		return (false);
	}
	if (!create_image(IMG_WINDOW, WINDOW_WIDTH, WINDOW_HEIGHT) \
		|| !create_window(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE))
	{
		cleanup_objects();
		return (false);
	}
	mlx_clear_window(get_mlx_ptr(), get_win_ptr());
	ft_mlx_hooks();
	mlx_loop(get_mlx_ptr());
	return (true);
}
