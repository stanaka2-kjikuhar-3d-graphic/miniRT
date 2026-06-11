/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 21:32:24 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/12 02:47:14 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H

/* File */
# define ERROR_FILE_BINARY "Invalid file: not a text file."

/* Color */
# define ERROR_COLOR_FORMAT "Invalid color: expected R,G,B (0-255)."
# define ERROR_COLOR_LEADING_ZERO "Invalid color: leading zero not allowed."
# define ERROR_COLOR_RANGE "Invalid color: value out of range (0-255)."

/* MLX */
# define ERROR_MLX_CONNECTION "MLX: Failed to create X-Window connection."
# define ERROR_MLX_WINDOW "MLX: Failed to create window."
# define ERROR_MLX_IMAGE "MLX: Failed to create image."
# define ERROR_MLX_IMAGE_DATA "MLX: Failed to get image data."

void	print_error(char const *msg);

#endif
