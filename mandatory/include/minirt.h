/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 15:42:05 by stanaka2          #+#    #+#             */
/*   Updated: 2026/04/06 17:03:06 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>
# include <string.h>

# include "libft.h"
# include "mlx.h"

# include <X11/keysym.h>
# include <X11/X.h>

# include "type.h"
# include "vec2.h"
# include "color.h"
# include "setting.h"
# include "map.h"
# include "player.h"

# include "error.h"
# include "cleanup.h"
# include "utils.h"
# include "parse_file.h"
# include "ft_mlx.h"
# include "game.h"

struct s_minirt
{
	t_setting	setting;
	t_mlx		mlx;
};

#endif
