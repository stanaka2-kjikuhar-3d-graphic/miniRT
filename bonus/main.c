/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 21:08:44 by stanaka2          #+#    #+#             */
/*   Updated: 2026/11/04 00:16:33 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

#include "mlx.h"
#include "ft_string.h"
#include "ft_lst.h"

#include "config.h"
#include "color.h"
#include "parser.h"
#include "light.h"
#include "object.h"
#include "window.h"
#include "window_buffer.h"
#include "logger.h"
#include "builder.h"
#include "loader.h"
#include "renderer.h"
#include "exporter.h"

static bool	is_valid_argument(int argc, char const *argv[]);
static int	run_window_mode(void);
static int	run_ppm_mode(char const *scene_path);
static void	cleanup(void);

int	main(int argc, char const *argv[])
{
	t_list	*scene_input;
	int		status;

	scene_input = NULL;
	if (!is_valid_argument(argc, argv))
	{
		print_log_program(LOG_ERROR, argv[0]);
		return (EXIT_FAILURE);
	}
	init_color_lut();
	if (!create_mlx_connection())
		return (EXIT_FAILURE);
	if (!parser(argv[1], &scene_input) \
		|| !loader(&scene_input) || !builder())
	{
		ft_lstclear(&scene_input, free);
		cleanup();
		return (EXIT_FAILURE);
	}
	if (argc == 3)
		status = run_ppm_mode(argv[1]);
	else
		status = run_window_mode();
	cleanup();
	return (status);
}

static bool	is_valid_argument(int argc, char const *argv[])
{
	char	*filename;
	size_t	len;

	if (argc != 2 && argc != 3)
		return (false);
	if (argc == 3 && ft_strcmp(argv[2], PPM_OPTION) != 0)
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

static int	run_window_mode(void)
{
	if (!setup_mlx_window())
		return (EXIT_FAILURE);
	setup_mlx_hooks();
	mlx_loop(get_mlx_ptr());
	return (EXIT_SUCCESS);
}

// ウィンドウを作らずに1枚描いて PPM に書き出す
static int	run_ppm_mode(char const *scene_path)
{
	if (!create_window_buffer(MAIN_WINDOW_BUFFER, WINDOW_WIDTH, WINDOW_HEIGHT) \
		|| !render_to_buffer() \
		|| !export_ppm(scene_path))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static void	cleanup(void)
{
	cleanup_object();
	cleanup_lights();
	cleanup_mlx();
}
