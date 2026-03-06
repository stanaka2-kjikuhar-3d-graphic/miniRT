# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/05 23:56:08 by stanaka2          #+#    #+#              #
#    Updated: 2026/03/06 14:25:59 by stanaka2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -------------------------- #
#         Phony Rules        #
# -------------------------- #

.PHONY: all bonus clean fclean re norm

# -------------------------- #
#      Makefile Setting      #
# -------------------------- #

SHELL =	/bin/bash

ifeq ($(filter re,$(MAKECMDGOALS)),re)
MAKEFLAGS += --no-print-directory
else
MAKEFLAGS += --no-print-directory -j
endif

RM = rm -f

# -------------------------- #
# 　　　　　　Target　　　      #
# -------------------------- #

NAME = miniRT

# -------------------------- #
# 　　     　LIBFT            #
# -------------------------- #

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INCLUDE_DIR = $(LIBFT_DIR)/include


# -------------------------- #
#         MINILIBX           #
# -------------------------- #

MINILIBX_DIR	= minilibx-linux
LIBMLX			= ${MINILIBX_DIR}/libmlx.a
MINILIBX_INCLUDE_DIR	= -I ${MINILIBX_DIR}
MINILIBX_LINK			= -lmlx -lXext -lX11 -L ${MINILIBX_DIR}

# -------------------------- #
# 　　　Compiler Flags        #
# -------------------------- #

CC				= cc
CFLAGS			= -Wall -Werror -Wextra
LIBMATH_FLAG	= -lm

# -------------------------- #
#          Include           #
# -------------------------- #

INCLUDE_DIR		= mandatory/include
INCLUDE			= -I $(INCLUDE_DIR) -I $(LIBFT_INCLUDE_DIR) ${MINILIBX_INCLUDE_DIR}
B_INCLUDE_DIR	= bonus/include
B_INCLUDE		= -I $(B_INCLUDE_DIR) -I $(LIBFT_INCLUDE_DIR) ${MINILIBX_INCLUDE_DIR}

# -------------------------- #
#     Source Directories     #
# -------------------------- #

SRC_DIRS	=	mandatory/src \
				$(addprefix mandatory/src/, \
				)

B_SRC_DIRS	=	bonus/src \
				$(addprefix bonus/src/, \
				)

# -------------------------- #
#        Source Files        #
# -------------------------- #

# mandatory
SRCS	=	main.c


# bonus
B_SRCS	=	main_bonus.c

# -------------------------- #
#       Bonus Switching      #
# -------------------------- #

ifeq ($(filter bonus,$(MAKECMDGOALS)),bonus)
SRC_DIRS = $(B_SRC_DIRS)
INCLUDE = $(B_INCLUDE)
SRCS = $(B_SRCS)
endif

# -------------------------- #
#        VPATH Setup         #
# -------------------------- #

# Dependency generation flags:
# foreach: Iterate over each directory in SRC_DIRS
# eval: Evaluate the string as Makefile syntax during parsing
# vpath %.c $(dir): Set search path for .c files in the specified directory
# Result: Make will search all SRC_DIRS when looking for .c source files
$(foreach dir,$(SRC_DIRS), $(eval vpath %.c $(dir)))

# -------------------------- #
#     Object & Dependency    #
# -------------------------- #

# patsubst: Pattern substitution function
OBJ_DIR		=	.obj
OBJS		=	$(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(SRCS)))
B_OBJS		=	$(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(B_SRCS)))

# -MT: Set the target name in the dependency file (uses automatic variable $@ for current target)
# -MMD: Generate dependency file (.d) during compilation, excluding system headers
# -MP: Add phony targets for each dependency to avoid errors when header files are deleted
# -MF: Specify the output path for the dependency file ($* is the stem without extension)
DEP_DIR		=	.dep
DEPFLAGS	=	-MT $@ -MMD -MP -MF $(DEP_DIR)/$*.d
DEPS		=	$(patsubst %.c, $(DEP_DIR)/%.d, $(notdir $(SRCS)))
B_DEPS		=	$(patsubst %.c, $(DEP_DIR)/%.d, $(notdir $(B_SRCS)))

# -------------------------- #
#    ANSI Escape Sequence    #
# -------------------------- #

DEF_COLOR	= \033[0;39m
GRAY 		= \033[0;90m
RED 		= \033[0;91m
GREEN 		= \033[0;92m
YELLOW 		= \033[0;93m
BLUE 		= \033[0;94m
MAGENTA 	= \033[0;95m
CYAN 		= \033[0;96m
WHITE 		= \033[0;97m

# -------------------------- #
#        Main Targets        #
# -------------------------- #

all: $(NAME)

bonus:	$(NAME)

# Link object files to create executable
# $^: All prerequisites (all .o files)
# |: Order-only prerequisites (directories must exist but don't trigger rebuild)
# $@: Target name ($(NAME))
$(NAME): $(OBJS) $(LIBFT) | ${LIBMLX}  
	@$(CC) $(CFLAGS) $^ -o $@ ${LIBMATH_FLAG} ${MINILIBX_LINK}
	@echo -e "[miniRT] $(GREEN)Build Complete:$(DEF_COLOR) $@"

# -------------------------- #
#        Build Rules         #
# -------------------------- #

# Pattern rule: compile .cpp to .o with dependency generation
# |: Order-only prerequisites (directories must exist but don't trigger rebuild)
# $<: First prerequisite (the .cpp file)
# $@: Target (the .o file)
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR) $(DEP_DIR)
	@$(CC) $(CFLAGS) $(DEPFLAGS) $(INCLUDE) -c $< -o $@

# Create object directory if it doesn't exist
# -: Ignore errors (no error if directory already exists)
$(OBJ_DIR):
	@-mkdir -p $@

# Create dependency directory if it doesn't exist
$(DEP_DIR):
	@-mkdir -p $@

# -------------------------- #
#         LIBFT Rule         #
# -------------------------- #

$(LIBFT):
	@echo -e "[miniRT] $(YELLOW)Build:$(DEF_COLOR) $@"
	@$(MAKE) -C $(LIBFT_DIR)


# -------------------------- #
#       MINILIBX Rule        #
# -------------------------- #

${LIBMLX}: | ${MINILIBX_DIR}
	@make -C ${MINILIBX_DIR}

${MINILIBX_DIR}:
	@curl -OL https://cdn.intra.42.fr/document/document/46275/minilibx-linux.tgz
	@tar xzf minilibx-linux.tgz
	@rm minilibx-linux.tgz
	@echo -e "[miniRT] $(GREEN)Install Complete:$(DEF_COLOR) $@"

# -------------------------- #
#         Debug Rules        #
# -------------------------- #

norm:
	@norminette -o mandatory bonus $(LIBFT_DIR) | grep Error || true

# -------------------------- #
#       Cleanup Rules        #
# -------------------------- #

# Remove object and dependency files only
clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@-$(MAKE) -C ${MINILIBX_DIR} clean
	@$(RM) $(OBJS) $(DEPS) $(B_OBJS) $(B_DEPS)
	@echo -e "[miniRT] $(BLUE)Deleted Compiled Files$(DEF_COLOR): *.o *.d"

# Remove everything including executable and directories
fclean:
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@-$(MAKE) -C ${MINILIBX_DIR} clean
	@$(RM) $(OBJS) $(DEPS) $(B_OBJS) $(B_DEPS)
	@echo -e "[miniRT] $(BLUE)Deleted Compiled Files$(DEF_COLOR): *.o *.d"
	@$(RM) -r $(NAME) $(OBJ_DIR) $(DEP_DIR)
	@echo -e "[miniRT] $(BLUE)Deleted Target File and Object File Dir$(DEF_COLOR): $(NAME) $(OBJ_DIR) $(DEP_DIR)"

# Full rebuild: clean everything and rebuild
re:	fclean all

# -------------------------- #
#  Include Dependency Files  #
# -------------------------- #

# Include all .d files (dependency files generated by -MMD)
# -: Ignore errors if .d files don't exist yet (first build)
-include $(DEPS) $(B_DEPS)
