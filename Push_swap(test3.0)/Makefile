# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cberganz <cberganz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/11 03:58:32 by cberganz          #+#    #+#              #
#    Updated: 2022/01/09 14:21:34 by cberganz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

INCLUDE		= include/

HEADER		= $(INCLUDE)push_swap.h

CC		= clang

CFLAGS		= -Wall -Wextra -Werror

SRC_NAME	= input_treatment.c			\
		  	utils_input_treatment.c		\
			utils_push_swap.c		\
			utils_lists.c			\
			utils_freememory.c		\
			utils_libft.c			\
			operations_swap.c		\
			operations_push.c		\
			operations_rotate.c		\
			operations_reverse_rotate.c	\
			push_swap_little.c		\
			push_swap_big.c			\
			list_playback.c			\
			optimized_a_movements.c		\
			optimized_b_movements.c		\
			main.c				\
			debug.c						# TO DELETE

SRC_DIR		= src/
SRC		= $(addprefix $(SRC_DIR), $(SRC_NAME))

OBJ_DIR		= objs/
OBJ_NAME	= $(SRC_NAME:.c=.o)
OBJ		= $(addprefix $(OBJ_DIR), $(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -g3

$(OBJ_DIR):
	mkdir -p $@

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@ -g3

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
