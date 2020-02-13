# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/31 10:53:16 by asolopov          #+#    #+#              #
#    Updated: 2020/02/13 14:48:54 by asolopov         ###   ########.fr        #
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

LEM_IN_SRCS			= main.c\
					input_process.c\
					print_functions.c \
					nodes_management.c\
					input_check.c\
					bfs_functions.c\
					queue_functions.c \
					paths_management.c \
					exit_functions.c \
					moving_ants.c\
					assigning_ants.c

JIRIS_LEM			= jiris_test_main.c \
					nodes_management.c \
					print_functions.c \
					bfs_functions.c \
					queue_functions.c \
					paths_management.c \
					exit_functions.c

LEM_IN_FILES		= $(addprefix $(LEM_IN_DIR), $(LEM_IN_SRCS))
JIRIS_IN			= $(addprefix $(LEM_IN_DIR), $(JIRIS_LEM))

# VISUAL files

VISU_HEX			= visu-hex

VISU_HEX_SRCS		= main.c\

VISU_HEX_FILES		= $(addprefix $(VISU_HEX_DIR), $(VISU_HEX_SRCS))

# Directories

LEM_IN_DIR			= ./srcs/lem-in/
VISU_HEX_DIR		= ./srcs/visu-hex/
LIBFT_DIR			= ./libft/
LIB_MLX_DIR			= ./libmlx/

# Libraries

LIBFT_NAME			= libft.a
MLX_NAME			= libmlx
MLX_A				= $(addprefix $(LIN_MLX_DIR), $(MLX_NAME))
LIBFT_A				= $(addprefix $(LIBFT_DIR), $(LIBFT_NAME))
LIBMLXFLAGS			= -I$(LIBMLX) -L$(LIBMLX) -lmlx -framework OpenGL -framework Appkit

# Includes
INCLUDES			= -I includes/ -I libft/

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(VISU_HEX)
	@echo "$(RED)Compiling lem_in...$(RES)"
	@gcc -o $(NAME) $(CFLAGS) $(LIBFT_A) $(LEM_IN_FILES)
	@echo "$(GREENB)$(NAME) $(GREEN)done.$(RES)"

$(VISU_HEX) : $(LIBFT_NAME)
	@echo "$(RED)Compiling visu-hex...$(RES)"
	@gcc -o $(VISU_HEX) $(CFLAGS) $(LIBFT_A) $(VISU_HEX_FILES) $(LIBMLXFLAGS)
	@echo "$(GREENB)$(VISU_HEX) $(GREEN)done.$(RES)"

$(LIBFT_NAME):
	@echo "$(RED)Compiling Libft Library$(RES)"
	@Make all -C $(LIBFT_DIR)
	@echo "$(GREEN)Done.$(RES)"
	@echo "$(RED)Compiling MLX Library$(RES)"
	@Make all -C $(MLX_A)
	@echo "$(GREEN)Done.$(RES)"

jiri:
	@rm -f jiris_test
	@gcc -o jiris_test $(CFLAGS) $(INCLUDES) $(JIRIS_IN) $(LIBFT_A)
	@echo "$(GREENB)Jiri's test file created$(RES)"

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