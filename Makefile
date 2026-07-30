# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/14 13:25:37 by kjikuhar          #+#    #+#              #
#    Updated: 2026/07/31 02:55:17 by stanaka2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -------------------------- #
#       Phony Targets        #
# -------------------------- #

.PHONY: all bonus clean fclean re install uninstall norm san debug test help

# -------------------------- #
#         Extra Flags        #
# -------------------------- #

ifeq ($(filter san,$(MAKECMDGOALS)),san)
override CFLAGS += -g -fsanitize=address,undefined
endif

ifeq ($(filter debug,$(MAKECMDGOALS)),debug)
override CFLAGS += -g
endif

EXTRA_FLAGS :=	MAKEFLAGS='$(MAKEFLAGS)' \
				CFLAGS='$(CFLAGS)' \
				CPPFLAGS='$(CPPFLAGS)'

# -------------------------- #
#      Makefile Setting      #
# -------------------------- #

OS	:= $(shell uname -s)

override MAKEFLAGS		+= -j --no-print-directory

override .DEFAULT_GOAL	:= all

.DEFAULT:
	@printf "$(RED)make: *** No rule to make target '$@'.  Stop.$(DEF_COLOR)\n"
	@$(MAKE) help;
	@exit 2

.DELETE_ON_ERROR:

help:
	@printf "$(CYAN)Usage:$(DEF_COLOR)\n"
	@printf "$(GREEN)all$(DEF_COLOR)        Build $(NAME)[mandatory part]\n"
	@printf "$(GREEN)bonus$(DEF_COLOR)      Build $(NAME)[bonus part]\n"
	@printf "$(GREEN)clean$(DEF_COLOR)      Remove object files, dependency files\n"
	@printf "$(GREEN)fclean$(DEF_COLOR)     Remove all generated files and directories\n"
	@printf "$(GREEN)re$(DEF_COLOR)         Rebuild with fclean and all\n"
	@printf "$(BLUE)install$(DEF_COLOR)    Install minilibx\n"
	@printf "$(BLUE)uninstall$(DEF_COLOR)  Remove minilibx\n"
	@printf "$(YELLOW)san$(DEF_COLOR)        Build with -g -fsanitize=address,undefined\n"
	@printf "$(YELLOW)debug$(DEF_COLOR)      Build with -g debug symbols\n"
	@printf "$(YELLOW)norm$(DEF_COLOR)       Run norminette\n"
	@printf "$(GRAY)help$(DEF_COLOR)       Show make rules\n"

# -------------------------- #
#           Target           #
# -------------------------- #

NAME	:= miniRT

# -------------------------- #
#       Compiler Flags       #
# -------------------------- #

CC	:= cc

override CFLAGS	+= -Wall -Wextra -Werror
# when submit, it should change -W3
override CFLAGS	+= -Wconversion -Wno-sign-conversion -Wshadow

# -------------------------- #
#          Include           #
# -------------------------- #

INCLUDE_DIRS		:=	bonus/include \
						$(addprefix bonus/include/, \
							scene \
							utils \
						)

override CPPFLAGS	+= $(foreach dir, $(INCLUDE_DIRS), -I$(dir))

# -------------------------- #
#     Source Directories     #
# -------------------------- #

SRC_DIRS	:= bonus/src
SRC_DIRS	+= $(addprefix bonus/src/, \
					parser \
					$(addprefix parser/, \
						read_next_line \
						parse_setting \
						parse_field \
						internal \
					) \
					renderer \
					$(addprefix renderer/, \
						path_tracing \
						phong \
						$(addprefix phong/, \
							lighting \
							shading \
						) \
					) \
					$(addprefix scene/, \
						camera camera/internal \
						light \
						object \
						$(addprefix object/, \
							circle \
							cylinder \
							cone \
							hyperboloid \
							paraboloid \
							plane \
							sphere \
							internal \
						) \
						viewport \
					) \
					$(addprefix utils/, \
						color \
						ft_error \
						$(addprefix vector/, \
							vec3 \
							vec2 \
							ivec2 \
						) \
						dynamic_array \
					) \
					ft_mlx \
					$(addprefix ft_mlx/, \
						hooks \
					) \
				)

$(foreach dir, $(SRC_DIRS), $(eval vpath %.c $(dir)))

# -------------------------- #
#        Source Files        #
# -------------------------- #

SRCS	:=	main.c

# ft_mlx
SRCS	+=	mlx_ptr.c \
			win_ptr.c \
			image.c \
			texture.c \
			cleanup_mlx.c \
			setup_mlx_window.c \
			setup_mlx_hooks.c \
			get_pixel_addr.c \
			get_uv_pixel_addr.c \
			calc_uv_pixel.c \
			put_color.c

# ft_mlx/hooks
SRCS	+=	expose_hook.c \
			loop_hook.c \
			key_press_hook.c \
			key_release_hook.c \
			button_hooks.c

# parser
SRCS	+=	parser.c \
			read_file_as_line_list.c \
			parse_settings.c
# parser/read_next_line
SRCS	+=	read_next_line.c
# parser/parse_setting
SRCS	+=	parse_ambient_light.c \
			parse_point_light.c \
			parse_spot_light.c \
			parse_camera.c \
			parse_plane.c \
			parse_sphere.c \
			parse_cylinder.c \
			parse_cone.c \
			parse_hyperboloid.c \
			parse_paraboloid.c \
			parse_required_fields.c \
			build_required_field.c \
			init_optional_fields.c \
			bind_material_option.c \
			parse_optional_fields.c \
			print_unknown_option_error.c \
			get_pattern_type.c \
			get_normal_type.c
# parser/parse_field
SRCS	+=	parse_vec3.c \
			parse_float.c \
			parse_color.c \
			parse_dir.c \
			parse_coordinate.c \
			parse_brightness.c \
			parse_fov.c \
			parse_radius.c \
			parse_half_height.c \
			parse_angle.c \
			parse_texture.c \
			parse_bool.c \
			parse_shininess.c \
			parse_size.c
# parser/internal
SRCS	+=	is_blank_line.c \
			is_comment_line.c \
			is_setting_id.c \
			is_option_id.c \
			count_split.c \
			free_split.c

# renderer
SRCS	+=	renderer.c \
			render_flag.c \
			put_color_to_window_image.c

# renderer/phong
SRCS	+=	phong.c \
			intersection.c
# renderer/phong/lighting
SRCS	+=	phong_lighting.c \
			phong_lighting_ambient.c \
			phong_lighting_point.c \
			phong_lighting_spot.c
# renderer/phong/shading
SRCS	+=	phong_shading.c

# scene/camera
SRCS	+=	camera.c \
			change_camera_pos.c \
			change_camera_dir.c \
			rotate_camera.c
# scene/camera/internal
SRCS	+=	calc_camera_dir.c \
			calc_camera_right.c \
			calc_camera_up.c

# scene/light
SRCS	+=	light.c \
			ambient_light.c \
			point_light.c \
			spot_light.c

# scene/object
SRCS	+=	object.c \
			calc_object_intersection.c \
			calc_object_uv.c \
			calc_object_color.c \
			calc_object_normal.c \
			calc_object_tbn.c \
			calc_bump_mapping.c \
			calc_normal_mapping.c
# scene/object/sphere
SRCS	+=	create_sphere.c \
			calc_sphere_intersection.c \
			calc_sphere_normal.c \
			calc_sphere_uv.c \
			calc_sphere_tbn.c
# scene/object/plane
SRCS	+=	create_plane.c \
			calc_plane_intersection.c \
			calc_plane_normal.c \
			calc_plane_uv.c \
			calc_plane_tbn.c
# scene/object/cylinder
SRCS	+=	create_cylinder.c \
			calc_cylinder_intersection.c \
			calc_cylinder_normal.c \
			calc_cylinder_uv.c \
			calc_cylinder_tbn.c
# scene/object/circle
SRCS	+=	create_circle.c \
			calc_circle_intersection.c \
			calc_circle_normal.c \
			calc_circle_uv.c \
			calc_circle_tbn.c
# scene/object/cone
SRCS	+=	create_cone.c \
			calc_cone_intersection.c \
			calc_cone_normal.c \
			calc_cone_uv.c
# scene/object/hyperboloid
SRCS	+=	create_hyperboloid.c \
			calc_hyperboloid_intersection.c \
			calc_hyperboloid_normal.c \
			calc_hyperboloid_uv.c
# scene/object/paraboloid
SRCS	+=	create_paraboloid.c \
			calc_paraboloid_intersection.c \
			calc_paraboloid_normal.c \
			calc_paraboloid_uv.c
# scene/object/internal
SRCS	+=	calc_onb.c \
			adjust_uv_range.c \
			set_material.c

# scene/viewport
SRCS	+=	viewport.c

# utils/color
SRCS	+=	add_color.c \
			mul_color.c \
			scale_color.c \
			init_color_lut.c \
			decode_color.c \
			encode_color.c \
			srgb.c \
			gamma.c \
			average_rgb.c \
			convert_uint_to_color.c

# utils/ft_error
SRCS	+=	error_line.c \
			error_field.c \
			print_error.c \
			print_argument_error.c \
			print_texture_error.c \
			print_errno.c \
			print_line_error.c \
			print_field_error.c

# utils/vector/vec3
SRCS	+=	vec3.c \
			vec3_add.c \
			vec3_sub.c \
			vec3_scale.c \
			vec3_dot.c \
			vec3_cross.c \
			vec3_length.c \
			vec3_normalize.c \
			vec3_rotate.c

# utils/vector/vec2
SRCS	+=	vec2.c

# utils/vector/ivec2
SRCS	+=	ivec2.c

# utils/dynamic_array
SRCS	+=	grow_dynamic_array.c

# -------------------------- #
#        Object Files        #
# -------------------------- #

OBJ_DIR	:= .obj

$(OBJ_DIR):
	@-mkdir -p $@

OBJS	:= $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

# -------------------------- #
#      Dependency Files      #
# -------------------------- #

DEP_DIR	:= .dep

$(DEP_DIR):
	@-mkdir -p $@

DEPS		:= $(patsubst %.c, $(DEP_DIR)/%.d, $(SRCS))
DEPFLAGS	= -MT $@ -MMD -MP -MF $(DEP_DIR)/$*.d

-include $(DEPS)
$(DEP_DIR)/%.d: ;

# -------------------------- #
#         LIBFT Rule         #
# -------------------------- #

LIBFT_DIR	:= libft

LIBFT		:= $(LIBFT_DIR)/libft.a

$(LIBFT):
	@printf "[miniRT] $(YELLOW)Build:$(DEF_COLOR) $@\n"
	@$(MAKE) -C $(LIBFT_DIR) $(EXTRA_FLAGS)

override CPPFLAGS	+= -I$(LIBFT_DIR)/include
override LDFLAGS	+= -L$(LIBFT_DIR)
override LDLIBS		+= -lft

# -------------------------- #
#       LIBMLX Rule          #
# -------------------------- #

LIBMLX_DIR	:= minilibx

install:
	@$(MAKE) uninstall
	@git clone https://github.com/42Paris/minilibx-linux.git $(LIBMLX_DIR)
	@printf "[miniRT] $(GREEN)Install Complete:$(DEF_COLOR) $(LIBMLX_DIR)\n"

uninstall:
	@$(RM) -r $(LIBMLX_DIR)
	@printf "[miniRT] $(GREEN)Uninstall Complete:$(DEF_COLOR) $(LIBMLX_DIR)\n"

$(LIBMLX_DIR):
	@$(MAKE) install

LIBMLX		:= $(LIBMLX_DIR)/libmlx.a

$(LIBMLX): | $(LIBMLX_DIR)
	@-$(MAKE) -s -C $(LIBMLX_DIR) > /dev/null 2>&1
	@printf "[$(NAME)] $(GREEN)Build Complete:$(DEF_COLOR) $@\n"

override CPPFLAGS	+= -I$(LIBMLX_DIR)
override LDFLAGS	+= -L$(LIBMLX_DIR)
ifeq ($(OS), Darwin)
override CPPFLAGS	+= -I/usr/X11/include
override LDFLAGS	+= -L/usr/X11/lib
endif
override LDLIBS	+= -lmlx -lXext -lX11

# -------------------------- #
#       Library Rules        #
# -------------------------- #

override LDLIBS	+= -lm

# -------------------------- #
#        Build Rules         #
# -------------------------- #

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJS) | $(LIBFT) $(LIBMLX)
	@$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@ $(LDFLAGS) $(LDLIBS)
	@printf "[$(NAME)] $(GREEN)Build Complete:$(DEF_COLOR) $@\n"

$(OBJ_DIR)/%.o: %.c | $(LIBMLX_DIR) $(OBJ_DIR) $(DEP_DIR)
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(DEPFLAGS) -c $< -o $@

# -------------------------- #
#        Cleanup Rules       #
# -------------------------- #

# Remove object and dependency files only
clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@-$(MAKE) -s -C $(LIBMLX_DIR) clean > /dev/null 2>&1
	@$(RM) $(OBJ_DIR)/* $(DEP_DIR)/*
	@printf "[$(NAME)] $(BLUE)Deleted Complete$(DEF_COLOR): *.o *.d\n"

# Remove everything
fclean:
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@-$(MAKE) -s -C $(LIBMLX_DIR) clean > /dev/null 2>&1
	@printf "[$(NAME)] $(BLUE)Delete Complete$(DEF_COLOR): $(LIBMLX) $(LIBMLX_DIR)/obj\n"
	@$(RM) $(OBJ_DIR)/* $(DEP_DIR)/*
	@printf "[$(NAME)] $(BLUE)Delete Complete$(DEF_COLOR): *.o *.d\n"
	@$(RM) -r $(NAME) $(OBJ_DIR) $(DEP_DIR)
	@printf "[$(NAME)] $(BLUE)Delete Complete$(DEF_COLOR): $(NAME) $(OBJ_DIR) $(DEP_DIR)\n"

# Full rebuild: clean everything and rebuild
re:
	@$(MAKE) fclean
	@$(MAKE) all $(EXTRA_FLAGS)

# -------------------------- #
#        Debug Rules         #
# -------------------------- #

san:
	@$(MAKE) re $(EXTRA_FLAGS)

debug:
	@$(MAKE) re $(EXTRA_FLAGS)

test:
	@bash test/test.sh

norm:
	@norminette -o bonus/src bonus/include $(LIBFT_DIR) | grep Error || true

# -------------------------- #
#    ANSI Escape Sequence    #
# -------------------------- #

DEF_COLOR := \033[0;39m
GRAY := \033[0;90m
RED := \033[0;91m
GREEN := \033[0;92m
YELLOW := \033[0;93m
BLUE := \033[0;94m
MAGENTA := \033[0;95m
CYAN := \033[0;96m
WHITE := \033[0;97m
