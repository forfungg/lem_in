# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/31 10:53:16 by asolopov          #+#    #+#              #
#    Updated: 2020/02/26 12:50:02 by jnovotny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Flags 'n colors

CFLAGS		=	-O3 #-Wall -Wextra -Werror
GREEN		=	\033[0;32m
GREENB		=	\033[1;32m
RES			=	\033[0m
RED			=	\033[0;31m

# LEM-IN files

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
					input_check2.c \
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
					ford_fulkerson_tools2.c \
					flow_paths.c \
					read_input.c \
					new_input_process.c

LEM_IN_FILES		= $(addprefix $(LEM_IN_DIR), $(LEM_IN_SRCS))
JIRIS_IN			= $(addprefix $(LEM_IN_DIR), $(JIRIS_LEM))

# VISU-HEXX files

VISU_HEXX			= visu-hexx

VISU_HEXX_SRCS		= controls.c\
					create_ant_nodes.c\
					exit_functions.c\
					images_tools.c\
					img_create_ant.c\
					img_create_back.c\
					img_create_lines.c\
					img_create_rooms.c\
					img_draw_ants.c\
					img_draw_lines.c\
					img_draw_visu-hexx.c\
					input_process.c\
					legend.c\
					lines_management.c\
					main.c\
					move_ants.c\
					nodes_management.c\
					paths_receive.c\
					print_functions.c\
					update_ant_position.c \
					assigning_ants.c \
					

VISU_HEXX_FILES		= $(addprefix $(VISU_HEXX_DIR), $(VISU_HEXX_SRCS))

# Directories

LEM_IN_DIR			= ./srcs/lem-in/
VISU_HEXX_DIR		= ./srcs/visu-hexx/
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

$(NAME): $(VISU_HEXX)
	@echo "$(RED)Compiling lem_in...$(RES)"
	@gcc -o $(NAME) $(CFLAGS) -I $(INCLUDES) $(LEM_IN_FILES) $(LIBFT_A)
	@echo "$(GREENB)$(NAME) $(GREEN)done.$(RES)"

$(VISU_HEXX) : $(LIBFT_NAME)
	@echo "$(RED)Compiling visu-hexx...$(RES)"
	@gcc -o $(VISU_HEXX) $(CFLAGS) -I $(INCLUDES) $(LIBFT_A) $(VISU_HEXX_FILES) $(LIBMLXFLAGS) -lpthread
	@echo "$(GREENB)$(VISU_HEXX) $(GREEN)done.$(RES)"

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
	@/bin/rm -f $(VISU_HEXX)
	@/bin/rm -f $(CHECKER_EXE)
	@Make fclean -C $(LIBFT_DIR)
	@Make fclean -C $(LIB_MLX_DIR)
	@echo "$(GREEN)Done.$(RES)"

re: fclean all