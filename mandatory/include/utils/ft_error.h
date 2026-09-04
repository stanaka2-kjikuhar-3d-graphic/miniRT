/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 21:32:24 by stanaka2          #+#    #+#             */
/*   Updated: 2026/08/10 19:17:50 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H

# include <stddef.h>

/* File */
# define ERROR_FILE_BINARY "not a text file"

/* Identifier / Scene */
# define ERROR_ID_UNKNOWN "unknown identifier"
# define ERROR_ID_DUP_A "duplicate ambient lighting (A)"
# define ERROR_ID_DUP_C "duplicate camera (C)"
# define ERROR_ID_NO_A "missing ambient lighting (A)"
# define ERROR_ID_NO_L "missing light (L)"
# define ERROR_ID_NO_C "missing camera (C)"

/* Element count */
# define ERROR_FIELDS_COUNT "invalid fields count"

/* Field syntax */
# define ERROR_INVALID_FORMAT "invalid format"
# define ERROR_INVALID_CHARACTER "invalid character"
# define ERROR_LEADING_ZERO "leading zero not allowed"
# define ERROR_ONLY_DIGITS "only digits allowed"
# define ERROR_EMPTY_COMPONENT "empty component"
# define ERROR_EMPTY_CHANNEL "empty channel"

/* Field value */
# define ERROR_OUT_OF_RANGE "out of range"
# define ERROR_MUST_BE_BOOL "must be true or false"
# define ERROR_MUST_BE_NORMALIZED "must be a unit vector"
# define ERROR_MUST_BE_EVEN "must be an even number"
# define ERROR_MUST_BE_FINITE "must be a finite number"
# define ERROR_TOO_SMALL "too small, half of it underflows to 0"
# define ERROR_HB_RADIUS "must exceed center_diameter"
# define ERROR_DEGENERATE_SCALE "shape is too small to place in the scene"

/* Material option */
# define ERROR_OPTION_FORMAT "missing '=' separator"
# define ERROR_OPTION_UNKNOWN "unknown key"
# define ERROR_OPTION_DUP "duplicate key"

/* MLX */
# define ERROR_MLX_CONNECTION "failed to create X-Window connection"
# define ERROR_MLX_WINDOW "failed to create window"
# define ERROR_MLX_IMAGE "failed to create image"
# define ERROR_MLX_XPM_IMAGE "failed to create xpm image"
# define ERROR_MLX_IMAGE_DATA "failed to get image data"

/* Hint: scene element syntax */
# define HINT_A "A brightness R,G,B"
# define HINT_L "L x,y,z brightness R,G,B"
# define HINT_C "C x,y,z nx,ny,nz fov"
# define HINT_SP "sp x,y,z diameter R,G,B"
# define HINT_PL "pl x,y,z nx,ny,nz R,G,B"
# define HINT_CY "cy x,y,z nx,ny,nz diameter height R,G,B"
# define HINT_CO "co x,y,z nx,ny,nz diameter height R,G,B"
# define HINT_HB "hb x,y,z nx,ny,nz center_diameter cap_diameter height R,G,B"
# define HINT_PB "pb x,y,z nx,ny,nz coefficient height R,G,B"
# define HINT_SL "sl x,y,z brightness R,G,B nx,ny,nz angle"
# define HINT_DL "dl nx,ny,nz brightness R,G,B"

/* Hint: field value range */
# define HINT_POSITIVE "0 < x"
# define HINT_NON_NEGATIVE "0 <= x"
# define HINT_BRIGHTNESS_RANGE "0.0 <= x <= 1.0"
# define HINT_FOV_RANGE "0 < x < 180"
# define HINT_ANGLE_RANGE "0 <= x <= 180"
# define HINT_COLOR_RANGE "0 <= x <= 255"
# define HINT_CHECKER_COUNT "2 <= n <= 1024"
# define HINT_CHECKER_COUNT_EVEN "2 <= n <= 1024, even number"
# define HINT_FLOAT_FINITE "FLT_MIN <= x <= FLT_MAX"

/* Hint: field syntax */
# define HINT_VECTOR "x,y,z"
# define HINT_COLOR "R,G,B (0-255)"
# define HINT_OPTION_FORMAT "key=value"

void	print_error(char const *msg);
void	print_argument_error(char const *program_name);
void	print_texture_error(char const *path, char const *msg);
void	print_errno(void);
void	set_error_line(size_t line_number, char const *line);
void	set_error_field(char const *field, char const *token);
void	print_line_error(char const *msg, char const *hint);
void	print_field_error(char const *msg, char const *hint);
void	print_field_error_multi_hints(char const *msg, char const **hints);

#endif
