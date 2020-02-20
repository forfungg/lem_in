# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/31 10:53:16 by asolopov          #+#    #+#              #
#    Updated: 2020/02/20 12:10:01 by jnovotny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Flags 'n colors

CFLAGS		=	-O3 #-Wall -Wextra -Werror
GREEN		=	\033[0;32m
GREENB		=	\033[1;32m
RES			=	\033[0m
RED			=	\033[0;31m

# LEM_IN files

NAME				= lem-in

LEM_IN_SRCS			= main.c \
					input_process.c \
					input_process2.c \
					input_process3.c \
					print_functions.c \
					nodes_management.c \
					nodes_management2.c \
					nodes_management3.c \
					nodes_management4.c \
					nodes_management5.c \
					input_check.c \
					bfs_functions.c \
					clear_memory.c \
					queue_functions.c \
					queue_functions2.c \
					paths_management.c \
					exit_functions.c \
					moving_ants.c \
					moving_ants_tools.c \
					assigning_ants.c \
					ford_fulkerson.c \
					ford_fulkerson_tools.c \
					flow_paths.c

LEM_IN_FILES		= $(addprefix $(LEM_IN_DIR), $(LEM_IN_SRCS))
JIRIS_IN			= $(addprefix $(LEM_IN_DIR), $(JIRIS_LEM))

# VISUAL files

VISU_HEX			= visu-hex

VISU_HEX_SRCS		= main.c\
					input_process.c\
					exit_functions.c\
					images_draw.c\
					images_tools.c\
					controls.c\
					line_drawing.c\
					bfs_functions.c\
					paths_management.c\
					print_functions.c\
					queue_functions.c\
					nodes_management.c\
					create_rooms.c\
					create_ant.c\
					create_back.c\
					create_lines.c
					

VISU_HEX_FILES		= $(addprefix $(VISU_HEX_DIR), $(VISU_HEX_SRCS))

# Directories

LEM_IN_DIR			= ./srcs/lem-in/
VISU_HEX_DIR		= ./srcs/visu-hex/
LIBFT_DIR			= ./libs/libft/
LIB_MLX_DIR			= ./libs/libmlx

# Libraries

LIBFT_NAME			= libft.a
MLX_NAME			= libmlx.a
MLX_A				= $(addprefix $(LIB_MLX_DIR), $(MLX_NAME))
LIBFT_A				= $(addprefix $(LIBFT_DIR), $(LIBFT_NAME))
LIBMLXFLAGS			= -I$(LIB_MLX_DIR) -L$(LIB_MLX_DIR) -lmlx -framework OpenGL -framework Appkit

# Includes
INCLUDES			= includes

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(VISU_HEX)
	@echo "$(RED)Compiling lem_in...$(RES)"
	@gcc -o $(NAME) $(CFLAGS) -I $(INCLUDES) $(LEM_IN_FILES) $(LIBFT_A)
	@echo "$(GREENB)$(NAME) $(GREEN)done.$(RES)"

$(VISU_HEX) : $(LIBFT_NAME)
	@echo "$(RED)Compiling visu-hex...$(RES)"
	@gcc -o $(VISU_HEX) $(CFLAGS) -I $(INCLUDES) $(LIBFT_A) $(VISU_HEX_FILES) $(LIBMLXFLAGS)
	@echo "$(GREENB)$(VISU_HEX) $(GREEN)done.$(RES)"

$(LIBFT_NAME):
	@echo "$(RED)Compiling Libft Library$(RES)"
	@Make all -C $(LIBFT_DIR)
	@echo "$(GREEN)Done.$(RES)"
	@echo "$(RED)Compiling MLX Library$(RES)"
	@Make all -C $(LIB_MLX_DIR)
	@echo "$(GREEN)Done.$(RES)"

clean:
	@echo "$(RED)Removing Object Files...$(RES)"
	@Make clean -C $(LIBFT_DIR)
	@Make clean -C $(LIB_MLX_DIR)
	@echo "$(GREEN)Done.$(RES)"

fclean: clean
	@echo "$(RED)Removing Executables & Library...$(RES)"
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(VISU_HEX)
	@/bin/rm -f $(CHECKER_EXE)
	@Make fclean -C $(LIBFT_DIR)
	@Make fclean -C $(LIB_MLX_DIR)
	@echo "$(GREEN)Done.$(RES)"

re: fclean all