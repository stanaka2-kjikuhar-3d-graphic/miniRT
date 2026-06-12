# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/14 13:25:37 by kjikuhar          #+#    #+#              #
#    Updated: 2026/06/12 12:24:09 by stanaka2         ###   ########.fr        #
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

CC				:= cc

override CFLAGS	+= -Wall -Wextra -Werror
# when submit, it should change -W3
override CFLAGS	+= -Wconversion -Wno-sign-conversion -Wshadow

# -------------------------- #
#          Include           #
# -------------------------- #

INCLUDE_DIRS		:= include

override CPPFLAGS	+= $(foreach dir, $(INCLUDE_DIRS), -I$(dir))

# -------------------------- #
#     Source Directories     #
# -------------------------- #

SRC_DIRS	:= src
SRC_DIRS	+= $(addprefix src/, \
					ft_error \
					ft_mlx ft_mlx/utils \
					object \
					parse_file parse_file/utils \
					phong_reflection_model \
					scene scene/utils\
					vector \
				)

$(foreach dir, $(SRC_DIRS), $(eval vpath %.c $(dir)))

# -------------------------- #
#        Source Files        #
# -------------------------- #

SRCS	:= 	main.c

# ft_error
SRCS	+=	print_error.c \
			print_errno.c

# ft_mlx
SRCS	+=	mlx_ptr.c \
			win_ptr.c \
			images.c \
			ft_mlx_destroy.c \
			ft_mlx_hooks.c \
			get_pixel_addr.c
SRCS	+=	expose_hook.c \
			key_press_hook.c

# object
SRCS		+=	object.c

# parse_file
SRCS	+=	parse_file.c \
			read_file_as_line_list.c \
			validate_setting_ids.c \
			parse_settings.c \
			parse_ambient_lighting_setting.c \
			parse_light_setting.c \
			parse_camera_setting.c \
			parse_plane_setting.c \
			parse_sphere_setting.c \
			parse_cylinder_setting.c
SRCS	+=	read_next_line.c \
			is_identifier.c \
			count_splitted.c \
			free_splitted.c \
			parse_color.c \
			parse_dir.c \
			parse_pos.c \
			parse_brightness.c \
			parse_fov.c \
			parse_diameter.c \
			parse_height.c \
			parse_dvec3.c \
			parse_double.c \
			parse_floating_point_format.c

# scene
SRCS	+=	ambient_lighting.c \
			camera.c \
			light.c \
			viewport.c
SRCS	+=	calc_camera_right.c \
			calc_camera_up.c

# vector
SRCS	+=	dvec3.c \
			dvec3_add.c \
			dvec3_sub.c \
			dvec3_length.c \
			dvec3_normalize.c \
			dvec3_scale.c \
			dvec3_dot.c \
			dvec3_cross.c \
			dvec3_rotate.c

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
	@bash TEST/test.sh

norm:
	@norminette -o src include $(LIBFT_DIR) | grep Error || true

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
