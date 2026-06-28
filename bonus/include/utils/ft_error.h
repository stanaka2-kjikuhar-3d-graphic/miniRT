/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 21:32:24 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/29 06:32:29 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H

/* File */
# define ERROR_FILE_BINARY "FILE: not a text file"

/* Identifier / Scene */
# define ERROR_ID_UNKNOWN "SCENE: unknown identifier"
# define ERROR_ID_DUP_A "SCENE: duplicate ambient lighting (A)"
# define ERROR_ID_DUP_C "SCENE: duplicate camera (C)"
# define ERROR_ID_NO_A "SCENE: missing ambient lighting (A)"
# define ERROR_ID_NO_L "SCENE: missing light (L)"
# define ERROR_ID_NO_C "SCENE: missing camera (C)"

/* Element count */
# define ERROR_A_COUNT "A: invalid fields count"
# define ERROR_L_COUNT "L: invalid fields count"
# define ERROR_C_COUNT "C: invalid fields count"
# define ERROR_SP_COUNT "sp: invalid fields count"
# define ERROR_PL_COUNT "pl: invalid fields count"
# define ERROR_CY_COUNT "cy: invalid fields count"
# define ERROR_SL_COUNT "sl: invalid fields count"
# define HINT_A "USAGE: A ratio R,G,B"
# define HINT_L "USAGE: L x,y,z brightness R,G,B"
# define HINT_C "USAGE: C x,y,z nx,ny,nz fov"
# define HINT_SP "USAGE: sp x,y,z diameter R,G,B"
# define HINT_PL "USAGE: pl x,y,z nx,ny,nz R,G,B"
# define HINT_CY "USAGE: cy x,y,z nx,ny,nz diameter height R,G,B"
# define HINT_SL "USAGE: sl x,y,z brightness R,G,B, nx,ny,nz angle"

/* Element */
# define ERROR_BRIGHTNESS_RANGE "BRIGHTNESS: out of range (0.0-1.0)"
# define ERROR_FOV_RANGE "FOV: out of range (0-180)"
# define ERROR_DIR_NOT_NORMALIZED "DIRECTION: must be a unit vector"
# define ERROR_DIAMETER_RANGE "DIAMETER: must be positive"
# define ERROR_DIAMETER_SMALL "DIAMETER: too small, diameter/2 underflows to 0"
# define ERROR_HEIGHT_RANGE "HEIGHT: must be positive"
# define ERROR_HEIGHT_SMALL "HEIGHT: too small, height/2 underflows to 0"
# define ERROR_ANGLE_RANGE "ANGLE: out of range (0-180)"

/* Floating Number */
# define ERROR_FLOAT_CHARACTER "FLOATING NUMBER: invalid character"
# define ERROR_FLOAT_LEADING_ZERO "FLOATING NUMBER: leading zero not allowed"

/* Vector */
# define ERROR_VECTOR_EMPTY "VECTOR: empty component"
# define ERROR_VECTOR_FORMAT "VECTOR: invalid format"
# define ERROR_VECTOR_CHARACTER "VECTOR: invalid character"
# define ERROR_VECTOR_LEADING_ZERO "VECTOR: leading zero not allowed"
# define HINT_VECTOR "USAGE: x,y,z"

/* Color */
# define ERROR_COLOR_EMPTY "COLOR: empty color channel"
# define ERROR_COLOR_FORMAT "COLOR: invalid format"
# define ERROR_COLOR_NON_DIGIT "COLOR: only digit allowed"
# define ERROR_COLOR_LEADING_ZERO "COLOR: leading zero not allowed"
# define ERROR_COLOR_RANGE "COLOR: value out of range (0-255)"
# define HINT_COLOR "USAGE: R,G,B (0-255)"

/* MLX */
# define ERROR_MLX_CONNECTION "MLX: failed to create X-Window connection"
# define ERROR_MLX_WINDOW "MLX: failed to create window"
# define ERROR_MLX_IMAGE "MLX: failed to create image"
# define ERROR_MLX_XPM_IMAGE "MLX: failed to create xpm image"
# define ERROR_MLX_IMAGE_DATA "MLX: failed to get image data"

void	print_error(char const *msg);
void	print_error_hint(char const *msg, char const *hint);
void	print_errno(void);

#endif
