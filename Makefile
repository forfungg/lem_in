# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/31 10:53:16 by asolopov          #+#    #+#              #
#    Updated: 2020/02/10 15:09:57 by jnovotny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Flags 'n colors

CFLAGS		=	-O3 #-Wall -Wextra -Werror
GREEN		=	\033[0;32m
GREENB		=	\033[1;32m
RES			=	\033[0m
RED			=	\033[0;31m

# LEM_IN files

NAME				= lem_in

LEM_IN_SRCS			= main.c\
					input_process.c

JIRIS_LEM			= jiris_test_main.c \
					nodes_management.c \
					print_functions.c \
					bfs_functions.c \
					queue_functions.c \
					paths_management.c \
					exit_functions.c

LEM_IN_FILES		= $(addprefix $(LEM_IN_DIR), $(LEM_IN_SRCS))
JIRIS_IN			= $(addprefix $(LEM_IN_DIR), $(JIRIS_LEM))

# Directories

LEM_IN_DIR			= ./srcs/
LIBFT_DIR			= ./libft/

# Libraries

LIBFT_NAME			= libft.a
LIBFT_A				= $(addprefix $(LIBFT_DIR), $(LIBFT_NAME))
MLX_LNK				= /usr/local/lib/ -l mlx -framework OpenGL -framework AppKit
MLX_HOME			= /usr/local/lib -lmlx -I /usr/local/X11/include -L/usr/X11/lib -lX11 -lXext -framework OpenGL -framework Appkit

# Includes
INCLUDES			= -I includes/ -I libft/

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT_NAME)
	@echo "$(RED)Compiling lem_in...$(RES)"
	@gcc -o $(NAME) $(CFLAGS) $(LIBFT_A) $(LEM_IN_FILES)
	@echo "$(GREENB)$(NAME) $(GREEN)done.$(RES)"

$(LIBFT_NAME):
	@echo "$(RED)Compiling Library$(RES)"
	@Make all -C $(LIBFT_DIR)
	@echo "$(GREEN)Done.$(RES)"

jiri:
	@rm -f jiris_test
	@gcc -o jiris_test $(CFLAGS) $(INCLUDES) $(JIRIS_IN) $(LIBFT_A)
	@echo "$(GREENB)Jiri's test file created$(RES)"

clean:
	@echo "$(RED)Removing Object Files...$(RES)"
	@Make clean -C $(LIBFT_DIR)
	@echo "$(GREEN)Done.$(RES)"

fclean: clean
	@echo "$(RED)Removing Executables & Library...$(RES)"
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(CHECKER_EXE)
	@Make fclean -C $(LIBFT_DIR)
	@echo "$(GREEN)Done.$(RES)"

re: fclean all