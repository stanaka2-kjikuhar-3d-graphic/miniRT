/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 21:32:24 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/12 14:04:31 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H

/* File */
# define ERROR_FILE_BINARY "Invalid file: not a text file."

/* Identifier / Scene */
# define ERROR_ID_UNKNOWN "Invalid scene: unknown identifier."
# define ERROR_ID_DUP_AMBIENT "Invalid scene: duplicate ambient lighting (A)."
# define ERROR_ID_DUP_LIGHT "Invalid scene: duplicate light (L)."
# define ERROR_ID_DUP_CAMERA "Invalid scene: duplicate camera (C)."
# define ERROR_ID_NO_AMBIENT "Invalid scene: missing ambient lighting (A)."
# define ERROR_ID_NO_LIGHT "Invalid scene: missing light (L)."
# define ERROR_ID_NO_CAMERA "Invalid scene: missing camera (C)."

/* Element count */
# define ERROR_AMBIENT_FEW "Invalid ambient lighting: missing fields."
# define ERROR_AMBIENT_MANY "Invalid ambient lighting: too many fields."
# define ERROR_LIGHT_FEW "Invalid light: missing fields."
# define ERROR_LIGHT_MANY "Invalid light: too many fields."
# define ERROR_CAMERA_FEW "Invalid camera: missing fields."
# define ERROR_CAMERA_MANY "Invalid camera: too many fields."
# define ERROR_SPHERE_FEW "Invalid sphere: missing fields."
# define ERROR_SPHERE_MANY "Invalid sphere: too many fields."
# define ERROR_PLANE_FEW "Invalid plane: missing fields."
# define ERROR_PLANE_MANY "Invalid plane: too many fields."
# define ERROR_CYLINDER_FEW "Invalid cylinder: missing fields."
# define ERROR_CYLINDER_MANY "Invalid cylinder: too many fields."

/* Element count hint */
# define HINT_AMBIENT "Usage: A ratio R,G,B"
# define HINT_LIGHT "Usage: L x,y,z brightness R,G,B"
# define HINT_CAMERA "Usage: C x,y,z nx,ny,nz fov"
# define HINT_SPHERE "Usage: sp x,y,z diameter R,G,B"
# define HINT_PLANE "Usage: pl x,y,z nx,ny,nz R,G,B"
# define HINT_CYLINDER "Usage: cy x,y,z nx,ny,nz diameter height R,G,B"

/* Value range / format */
# define ERROR_BRIGHTNESS_RANGE "Invalid brightness: out of range (0.0-1.0)."
# define ERROR_FOV_RANGE "Invalid FOV: out of range (0-180)."
# define ERROR_DIR_NOT_NORMALIZED "Invalid direction: must be a unit vector."
# define ERROR_DIAMETER_RANGE "Invalid diameter: must be positive."
# define ERROR_HEIGHT_RANGE "Invalid height: must be positive."
# define ERROR_VECTOR_FORMAT "Invalid vector: expected x,y,z."
# define ERROR_NUMBER_FORMAT "Invalid number: bad floating-point value."
# define ERROR_NUMBER_LEADING_ZERO "Invalid number: leading zero not allowed."

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
void	print_error_hint(char const *msg, char const *hint);
void	print_errno(void);

#endif
