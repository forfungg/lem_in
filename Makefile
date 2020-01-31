# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/31 10:53:16 by asolopov          #+#    #+#              #
#    Updated: 2020/01/31 16:17:03 by asolopov         ###   ########.fr        #
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

LEM_IN_FILES		= $(addprefix $(LEM_IN_DIR), $(LEM_IN_SRCS))

# Directories

LEM_IN_DIR			= ./srcs/
LIBFT_DIR			= ./libft/

# Libraries

LIBFT_NAME			= libft.a
LIBFT_A				= $(addprefix $(LIBFT_DIR), $(LIBFT_NAME))
MLX_LNK				= /usr/local/lib/ -l mlx -framework OpenGL -framework AppKit
MLX_HOME			= /usr/local/lib -lmlx -I /usr/local/X11/include -L/usr/X11/lib -lX11 -lXext -framework OpenGL -framework Appkit

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