# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/14 13:25:37 by kjikuhar          #+#    #+#              #
#    Updated: 2026/06/25 21:34:32 by stanaka2         ###   ########.fr        #
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
						read_file \
						parse_setting \
						parse_element \
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
					) \
					ft_mlx ft_mlx/internal \
				)

$(foreach dir, $(SRC_DIRS), $(eval vpath %.c $(dir)))

# -------------------------- #
#        Source Files        #
# -------------------------- #

SRCS	:=	main.c

# ft_mlx
SRCS	+=	mlx_ptr.c \
			win_ptr.c \
			images.c \
			get_pixel_addr.c \
			ft_mlx_hooks.c \
			ft_mlx_destroy.c
# ft_mlx/internal
SRCS	+=	expose_hook.c \
			loop_hook.c \
			key_press_hook.c \
			key_release_hook.c \
			button_hooks.c

# parser
SRCS	+=	parser.c \
			validate_setting_ids.c
# parser/read_file
SRCS	+=	read_file_as_line_list.c \
			read_next_line.c
# parser/parse_setting
SRCS	+=	parse_settings.c \
			parse_ambient_light_setting.c \
			parse_light_setting.c \
			parse_camera_setting.c \
			parse_plane_setting.c \
			parse_sphere_setting.c \
			parse_cylinder_setting.c
# parser/parse_element
SRCS	+=	parse_vec3.c \
			parse_float.c \
			parse_color.c \
			parse_dir.c \
			parse_pos.c \
			parse_brightness.c \
			parse_fov.c \
			parse_radius.c \
			parse_half_height.c \
			parse_angle.c
# parser/internal
SRCS	+=	is_identifier.c \
			count_split.c \
			free_split.c

# renderer
SRCS	+=	renderer.c \
			render_flag.c

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
			intersect.c \
			calc_normal.c \
			get_object_color.c
# scene/object/sphere
SRCS	+=	add_sphere.c \
			intersect_sphere.c \
			calc_sphere_normal.c
# scene/object/plane
SRCS	+=	add_plane.c \
			intersect_plane.c \
			calc_plane_normal.c
# scene/object/cylinder
SRCS	+=	add_cylinder.c \
			intersect_cylinder.c \
			calc_cylinder_normal.c
# scene/object/circle
SRCS	+=	add_circle.c \
			intersect_circle.c \
			calc_circle_normal.c
SRCS	+=	compute_onb.c

# scene/viewport
SRCS	+=	viewport.c

# utils/color
SRCS	+=	add_color.c \
			mul_color.c \
			scale_color.c \
			calc_rgb.c

# utils/ft_error
SRCS	+=	print_error.c \
			print_errno.c

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
